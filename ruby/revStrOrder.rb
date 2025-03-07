def reverseOrder(fname,lname) 
  fullName="#{fname} #{lname}"
  revName=fullName.split.reverse.join(' ')
  return revName
end
def reverseStr(fname,lname) 
  fullName="#{fname} #{lname}"
  revName=fullName.reverse
  return revName
end

print "Enter the first name="
fname= gets.chomp.to_s  
print "Enter the last name="
lname= gets.chomp.to_s 
revStr=reverseOrder(fname,lname)
puts revStr

revStr=reverseStr(fname,lname)
puts revStr