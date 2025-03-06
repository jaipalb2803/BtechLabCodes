myNum= complex(3,2)
realPart = myNum.real
imagPart = myNum.imag
print("Real part of {} is {}".format(myNum,realPart))
print("Imaginary part of {} is {}".format(myNum,imagPart))

#python
import fractions
myNum = fractions.Fraction(3.6)
print("Data type of {} is {}".format(myNum,type(myNum)))

import math
myNum=556
result=math.log(myNum,5)
print("Log of {} to base 5 is {}.".format(myNum,result))

import random
myNum=random.randint(0,100000)
print("The random Integer value is:",myNum)
k=int(input())
if(k==myNum):
    print("you entered OTP SUCESSFULLY !!")

