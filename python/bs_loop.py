# python programe
print("Enter any two numbers:")
a=int(input()) 
b=float(input())
print("Enter your choice:")
print("1.add\n2.sub\n3.mul\n4.div")
c=int(input()) 
if c==1:
    print("result is=",a+b)
elif c==2:
    print("result is=",a-b)
elif c==3:
    print("result is=",a*b)
elif c==4:
    print("result is=",a/b)
else:
    print("please! correct option")