# hash table key=>value
studMarks={}

puts "Enter no.of the subjects:"
n=gets.chomp.to_i
n.times do 
  puts "Enter subject name:"
  sub=gets.chomp.to_s
  puts "Enter #{sub} Marks:"
  mrk=gets.chomp.to_i
  studMarks[sub]=mrk
end

tolMrk=studMarks.values.sum
print "Total marks of all subject is: #{tolMrk}"
