print "Enter filename="
f=gets.chomp.to_str

if(File.exist?(f))
   print "Extension=#{File.extname(f)}\n"
   print "Abs=#{File.absolute_path(f)}\n"
   print "base=#{File.basename(f)}\n"
   print "dir=",File.dirname(f),"\n"
else
   print "Invalid\n"
end      