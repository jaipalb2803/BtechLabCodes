#User function Template for python3

class Solution:
   def checkCompressed(self, S, T):
    i = j = 0
    while i < len(S) and j < len(T):
        if S[i] == T[j]:
            i += 1
            j += 1
        elif T[j].isdigit() and S[0]==T[0]:
            count = int(T[j])
            i += count
            j += 1
        else:
            return 0
    if(i == len(S) and j == len(T)):
        print(i,len(S),j,len(T))
        return 1
    else:
        return 0




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    #t = int (input ())
    #for _ in range (t):
        S = input()
        T = input()
        
        ob = Solution()
        print(ob.checkCompressed(S,T))
# } Driver Code Ends