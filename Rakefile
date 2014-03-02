desc "Compile C-ext and run tests"
task :default => [:clean, :build_gem] do
  puts "\n\n\n\n"
  puts '*' * 30
  puts 'Executing tests...'
  puts '*' * 30
  sh('ruby', '-I.', 'test.rb')
end

desc "Build gem"
task :build_gem => [:gen_make] do
  sh('make')
end

desc "Generate Makefile"
task :gen_make do
  sh('ruby extconf.rb')
end

desc "Clean"
task :clean do
  sh('rm -f Makefile *.o *.bundle')
end
