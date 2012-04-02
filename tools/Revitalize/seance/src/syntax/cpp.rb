module CppGen

      FASTCALL_THIS = "__this"

      STDCALL = :stdcall
      FASTCALL = :fastcall
      THISCALL = :thiscall

      CC_KEYWORD = {
        STDCALL => "__stdcall",
        FASTCALL => "__fastcall",
        THISCALL => "__thiscall",
      }

      KEYWORD_CC = CC_KEYWORD.invert

      def self.to_c_name(nam)
        nam.gsub(':','_')
      end

      def self.format_args(args, implicit_this, cc, force_cc)
        if cc == force_cc
        elsif force_cc == FASTCALL
          if cc == THISCALL
            args = args.clone
            args.insert(1, ["int", "" ])
            args[0][1] = FASTCALL_THIS
          else
            raise "Unsupported: Conversion from #{cc} to #{force_cc}"
          end
        elsif force_cc == STDCALL || force_cc == THISCALL || implicit_this 
          if cc == THISCALL
            args = args[1..-1]
          else
            raise "Unsupported: conversion from #{cc} to #{force_cc}"
          end
        end

        args.map{ |(t, n)| t+" "+n}.join(",")
      end



      ###Gives a declaration for the method (minus the convention)
      ###Options:
      ###name_override: Gives a declaration for a function with the same type and convention, but a different name
      ###implicit_this: Same as :force_cc => THISCALL
      ###force_cc: Alters the declaration to match that of a different calling convention.
      ###          Currently supports thiscall -> fastcall (inserts dummy second argument; alters name of first arg to FASTCALL_THIS),
      ###          thiscall -> stdcall (removes first argument)
      ###          and * -> thiscall (also removes first argument)
      ###
      ###          Note that the input function is Hex-Rays pseudo-C, while the output is C++
      ###          Hence, the "this" parameter is explicit in thiscall functions in the database,
      ###          but is made implicit when forcing to thiscall here
      def self.get_func_decl(nam, type, args, convention, opts = {})
        defaults = {:name_override => nam, :implicit_this => false, :force_cc => nil}
        opts = defaults.merge(opts)

        args_str = format_args(args, opts[:implicit_this], convention, opts[:force_cc])
        
        if opts[:force_cc] != nil && opts[:force_cc] != THISCALL
          opts[:name_override] = to_c_name(nam)
        end

        cc = opts[:force_cc] == nil ? "" : " "+CC_KEYWORD[opts[:force_cc]]
        "#{type}#{cc} #{opts[:name_override]}(#{args_str})"
      end
end
