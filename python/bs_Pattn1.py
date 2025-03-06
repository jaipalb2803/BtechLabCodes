# python programe                       
print("how many rows :",end=" ")        
n=int(input())
print("PATTERN-1")
for i in range(0,n):
    for j in range(0,i):
        print(" ",end=" ")
    for i in range(i,n):
        print("*",end=" ")
    print("\n")
    
#python programe-2
print("PATTERN-2")
for i in range(0,n+1):
    for j in range(0,i):
         print("*",end=" ")  
    print("\n")