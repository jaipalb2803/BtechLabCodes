def checkTemp(t1,t2)
    if(t1<0 && t2>100) || (t2<0 && t1>100)         
        true
    else                        
        false
   end
end 
print "Please Enter the 1st Temperature="
t1=gets.chomp.to_i
print "Please Enter the 2nd Temperature="
t2=gets.chomp.to_i

res=checkTemp(t1,t2)
print "Result:",res