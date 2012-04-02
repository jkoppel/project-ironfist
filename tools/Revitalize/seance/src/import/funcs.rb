
module Seance
  module Import

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

      refined.map do |s|
        md = /(.+?)(\w+)$/.match(s) #Uses a non-capturing group
        [md[1].chomp, md[2].chomp]
      end
    end

    def self.parse_sig(sig)
      sig = sig.strip
      re = /^(.+)(__thiscall|__stdcall|__cdecl|__fastcall) ([\w:]+)\((.+)\)$/
      md = re.match(sig)
      
      if md.nil?
        p sig
        raise "Function signature did not correspond to expected format"
      else
        {:type => md[1].strip,
          :convention => md[2],
          :name => md[3],
          :args => parse_args(md[4])}
      end
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
      f = File.open(filnam, "r")
      puts filnam
      sig = f.readline
      sig = f.readline while sig =~ /\/\//
      body = f.readlines.join
      f.close

      comps = parse_sig(sig)

      db = FuncDB.new(root)
      db.add_func(comps[:type], comps[:name], comps[:convention], comps[:args], body)
    end

  end
end
