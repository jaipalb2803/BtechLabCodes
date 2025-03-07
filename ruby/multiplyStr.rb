def multiply_string(str, n)
  return (str+" ") * n
end

puts "Enter the string="
str= gets.chomp.to_s   

puts "Enter the no of copies="
num= gets.chomp.to_i
newStr = multiply_string(str, num)

puts newStr