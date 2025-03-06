#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    string s;
    cout<<"enter your name:";
    getline(cin,s);
    int k=s.length();
    string::iterator it;
    it = s.end();
    for(int i=0;i<=k;i++)
    {
         cout << * it; 
         it--;
    }

}