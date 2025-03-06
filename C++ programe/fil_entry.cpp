#include<iostream>
#include<bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
    char s[50];
    fstream st,st2; // Step 1: Creating object of fstream class
    st.open("sample.txt",ios::out);  // Step 2: Creating new file
    
    if(!st) // Step 3: Checking whether file exist
    {
        cout<<"File creation failed";
    }
    else
    {
        cout<<"New file created\n";
        cin.get(s,50);
        st<<s;
        cout<<"position="<<st.tellp()<<endl;
        st.seekp(3);
        st<<'#';
        st.close();

        st2.open("sample.txt",ios::in);
        char ch;
        cout<<"position="<<st2.tellg()<<endl;
        while (!st2.eof())
        {
            st2 >>ch;  // Step 4: Reading from file
            cout << ch;   // Message Read from file
        }
        st2.close(); 
       // st.close(); // Step 4: Closing file
    }
    //
    return 0;
}