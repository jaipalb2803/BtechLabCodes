#include<iostream>
using namespace std;

class cls
{
private:
    int a,b;
public:
    void foo(int x,int y)
    {
        a=x; b=y;
    }
    friend void pnt(cls k);
};
void pnt(cls k)
{
    cout<<k.a<<" "<<k.b<<endl;
}
int main()
{
    int x,y;
    cout<<"enter a,b=";
    cin>>x>>y;
    cls k;
    k.foo(x,y);
    pnt(k);
}