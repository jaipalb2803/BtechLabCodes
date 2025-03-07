def greatestNum(n1,n2,n3)
    if(n1>=n2 && n1>=n3)        
        return n1
    elsif(n2>=n1 && n2>=n3)     
        return n2
    else                        
        return n3
  end
end 

print "Please Enter the 1st Number="
n1=gets.chomp.to_i
print "Please Enter the 2nd Number="
n2=gets.chomp.to_i
print "Please Enter the 3rd Number="
n3=gets.chomp.to_i

num=greatestNum(n1,n2,n3)
puts "The greatest Number of Three= #{num}"
