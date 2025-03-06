#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class base
{
     private:
        int x;
     public:
       void read(int v);
       void operator++(int)
       {
          x=x+1;   
       }
       friend void print(base a );
};
void base::read(int v)
{
    x=v;
   
}
void print(base a)
{
    
    cout<<"x="<<a.x<<endl;
    
}
class derive:public base
{
    protected:
    int a1,a2;
    public:
    void read(int x,int y)
    {
        a1=x;
        a2=y;
    }
    derive(int x)
    {
        cout<<"hi"<<endl;
    }
    ~derive()
    {
        cout<<"buy";
    }

};
int main()
{
    int v;
    base b;
    derive a(5);
    cout<<"enter a=";
    cin>>v;

    b.read(v);
    print(a);
    a++;
    print(a);

    
}