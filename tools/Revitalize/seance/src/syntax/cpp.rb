module CppGen

  ARG_SIZE = 4 #I fear how easy it is to spread the 32-bit assumption throughout

  FASTCALL_THIS = "__this"

  STDCALL = :stdcall
  FASTCALL = :fastcall
  THISCALL = :thiscall
  CDECL = :cdecl

  CC_KEYWORD = {
    STDCALL => "__stdcall",
    FASTCALL => "__fastcall",
    THISCALL => "__thiscall",
    CDECL => "__cdecl"
  }

  CC_PREFIX = {
    STDCALL => "_",
    FASTCALL => "@",
    THISCALL => "?",
    CDECL => "_"
  }

  KEYWORD_CC = CC_KEYWORD.invert

  def self.to_c_name(nam)
    nam.gsub(':','_')
  end

  def self.convert_args(args, implicit_this, cc, force_cc)
    if cc == force_cc
    elsif force_cc == FASTCALL
      if cc == THISCALL
        args = args.clone
        args.insert(1, ["int", "" ])
        args[0][1] = FASTCALL_THIS
      else
        raise "Unsupported: Conversion from #{cc} to #{force_cc}"
      end
    elsif [STDCALL,THISCALL,CDECL].index(force_cc) || implicit_this 
      if cc == THISCALL
        args = args[1..-1]
      else
        raise "Unsupported: conversion from #{cc} to #{force_cc}"
      end
    end

    args
  end

  def self.format_args(args, implicit_this, cc, force_cc)
    convert_args(args,implicit_this, cc, force_cc).map{ |(t, n)| t+" "+n}.join(",")
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

  def self.get_size_for_nargs(nargs)
    ARG_SIZE * nargs
  end

  def self.get_esp_diff(conv, n_stackargs)
    case conv
    when CDECL
      get_size_for_nargs(n_stackargs)
    else
      0
    end
  end

  def self.prefix_for_cc(c)
    CC_PREFIX[c]
  end

  def self.keyword_to_cc(k)
    CC_KEYWORD[k]
  end

  def self.cc_to_keyword(cc)
    KEYWORD_CC[cc]
  end

  class FuncSig
    attr_reader :type, :name, :raw_name, :conv, :args

    def initialize(ret_type, name, raw_name, cc, args)
      @type = ret_type
      @name = name
      @conv = cc
      @args = args
      @raw_name = raw_name
    end

    def arg_names
      args.map {|(_, n)| n}
    end

    def arg_size(force_cc=nil)
      CppGen.get_size_for_nargs(CppGen.convert_args(@args, false, @conv, force_cc).size)
    end
    
    def stack_arg_names
      case @conv
      when THISCALL
        args = @args[1..-1]
      when FASTCALL
        args = @args[2..-1]
      when STDCALL
        args = @args
      when CDECL
        args = @args
      end
      
      args ||= []
      args.map{|(_,n)| n}
    end
    
    def register_args
      case @conv
      when THISCALL
        [["ecx", @args[0][1]]]
      when FASTCALL
        ["ecx","edx"].zip(@args.map{|(_,nam)| nam})
      when STDCALL
        []
      when CDECL
        []
      end
    end

    def gen_decl(opts = {})
      CppGen.get_func_decl(@name, @type, @args, @conv, opts)
    end

    def esp_diff
      CppGen.get_esp_diff(@conv, stack_arg_names.size)
    end

    def to_function_sig
      if @conv == THISCALL
        FuncSig.new(@type, CppGen.to_c_name(@name), THISCALL, [[@args[0][0], FASTCALL_THIS]]+@args[1..-1])
      else
        self
      end
    end
  end
  
end

