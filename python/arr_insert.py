# python programe for insertion
import array as a
n=a.array('i',[1,2,4,7,8,9])
print("your array:")
for i in n:
    print(i,end=" ")
c=0
for i in range(0,6):
    if n[i]%2==0:
        c+=1
    if i==5:
      print("\ntotal number of even integer is",c)

print("enter insertion position :",end="")
p=int(input())
print("enter  insertion value :",end="")
v=int(input())

n.insert(p-1,v)
for i in n:
   print(i,end=" ")
c=0
for i in range(0,6):
    if n[i]%2==0:
        c+=1
    if i==5:
      print("\n Now total number of even integer is",c)
      
######General format############
def main():
   a=list(map(str,input().split()))
   a.sort(reverse=True)
   d="".join(a)
   print(d)
if __name__=='__main__':
    main()      