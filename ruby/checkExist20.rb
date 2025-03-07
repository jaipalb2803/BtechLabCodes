def checkAnyNumIs20Exist(n1,n2)
    if(n1==20 || n2==20)        
        true
    else                        
        n1+n2
  end
end 
print "Please Enter the 1st Number="
n1=gets.chomp.to_i
print "Please Enter the 2nd Number="
n2=gets.chomp.to_i

res=checkAnyNumIs20Exist(n1,n2)
print "Result:",res