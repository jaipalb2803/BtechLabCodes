import random
pass1=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r',
      's','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0',
      'A','B','C','D','E','F','G','H','J','K','L','M','N','O','P','Q','R','S',
       'T','U','V','W','X','Y','Z']
password=""
for i in range(6):
   password+=random.choices(pass1)[0]
print("your password is:",password)


         