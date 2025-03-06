//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    string reverseWords(string S) 
    { 
        stack<string> words;  
        string currWord = "";

      for (char c : S)
      {
         if (c == '.') 
         {
            words.push(currWord);
            currWord = "";  
         } 
         else 
         {
            cout<<c<<endl;
            currWord += c;  
         }
      }

     words.push(currWord);

     string result = "";
     while (!words.empty())
     {
        result += words.top() + ".";
        words.pop();
     }

    result.pop_back();
    return result;
 
    } 
};

int main() 
{
    int t;
    cout<<"enter no of test cases=";
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
