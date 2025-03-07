#include<iostream>
#include<cstring>
using namespace std;

struct google
{
    string s;
    int id;
    void readDtl(void )
    {
        cout<<"Enter employ name:";
        cin>>s;
        cout<<"Enter employ details=";
        cin>>id;
    }

};
void printDtl( struct google emp)
{
      cout<<"Employee name :"<<emp.s<<endl;
      cout<<"Employee id="<<emp.id<<endl;
}
int main()
{
    google emp;
    emp.readDtl();
    printDtl(emp);

}