def calPerimeter(r)
  return 2*Math::PI*r
end
def calArea(r)
  return Math::PI*r*r
end

print "Enter the radius of circle="
r= gets.chomp.to_i   
p= calPerimeter(r)
a= calArea(r)
print "Circle Perimetre=",p.round(2)," and Area=",a.round(2)