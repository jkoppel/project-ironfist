require 'yaml'

module Seance

  module Import

    class ImportException < Exception
    end


    def self.parse_args(argstr)
      guess = argstr.split(/,/)
      
      refined = []

      cur_arg = ""

      guess.each do |s|
        cur_arg << s
        if parens_balanced(cur_arg)
          refined << cur_arg
          cur_arg = ""
        else
          cur_arg << ","
        end
      end

      failed = false

      ref = refined.map do |s|
        md = /(.+?)(\w+)$/.match(s) #Uses a non-capturing group
        if md.nil?
          failed = true
          next
        end
        [md[1].chomp, md[2].chomp]
      end

      if failed
        nil
      else
        ref
      end
    end

    def self.parse_sig(sig)
      if sig.index("__usercall ") || sig.index("__userpurge ")
        raise ImportException, "Function signature '#{sig.strip}' specifies a non-standard calling convention, and cannot be processed'"
      end

      sig = sig.strip
      re = /^(.+)(__thiscall|__stdcall|__cdecl|__fastcall) ([\w:]+)\((.*)\)$/
      md = re.match(sig)

      if md.nil?
        raise ImportException, "Function signature did not correspond to expected format"
      end
      
      type = md[1].strip
      conv = md[2]
      name = md[3]
      args = parse_args(md[4])
      
      if args.nil?
        raise ImportException, "Function #{name} has unsupported signature (e.g.: array arguments, function-pointer arguments)"
      end
      
      {:type => type,
        :convention => conv,
        :name => name,
        :args => args}
    end

    def self.parens_balanced(str)
      bal = 0
      
      str.each_char do |c|
        if c=='('
          bal += 1
        elsif c==')'
          bal -= 1
          return false if bal < 0
        end
      end
      
      bal == 0
    end

    def self.import_func(filnam, root)
      h = YAML.load_file(filnam)

      raw_name = h['raw_name']
      
      lines = h['body'].split(/\n/)
      
      sig = lines[0]
      
      body = lines[1..-1].join("\n")

      comps = parse_sig(sig)

      db = FuncDB.new(root)
      db.add_func(comps[:type], comps[:name], raw_name,
                  comps[:convention], comps[:args], body)
    end

  end
end
