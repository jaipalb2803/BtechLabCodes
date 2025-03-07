print "Please Enter the filename="
filename=gets.chomp

extn=File.extname(filename)
puts "The Extension of the file is: #{extn}"
base=File.basename("D:\ scriptPrgm\ruby")
puts "The Base of the file is: #{base}"
dir=File.dirname("D:\scriptPrgm\ruby")
puts "The DirName of the file is: #{dir}"
res=File.directory?("Dogs")
puts "The Directory of the file is: #{res}"
