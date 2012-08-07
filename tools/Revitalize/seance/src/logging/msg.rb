module Seance
  module Logger

    class RecoverableError < Exception
    end

    def self.with_error_handling(on_err=proc{nil})
      begin
        yield
      rescue RecoverableError
        on_err.call
      end
    end

    def self.error(msg)
      puts "Error: #{msg}"
      raise RecoverableError
    end
  end
end
