
t = int(input())

def count_pair_div_2(a,n):
    count=0
    for i in range(n):
       for j in range(i+1,n):
          if(a[i]+a[j])%2==0:
             count+=1  
    return count    

while t > 0:
    # Your code goes here
    n=int(input())
    a = list(map(int, input().split()))
    print(count_pair_div_2(a,n))        
    t -= 1

    