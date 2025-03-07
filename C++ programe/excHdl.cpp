// C++ Program to Demonstrate
// Operator Overloading
#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cout<<"enter a and b=";
	cin>>a>>b;
	try
	{
		if(b==0)
			throw b;
		cout<<a/b;
	}
	catch(/*const std::*/exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
/*#include <iostream>
using namespace std;

void func(int a,int b)
{
	if(b==0)
	{
		throw"expection throw";
	}
	cout<<"res="<<a/b;
}
int main()
{
	int a,b,c;
	cout<<"enter a and b=";
	cin>>a>>b;
	try
	{
		func(a,b); 
		
	}
	catch(const char* e)
	{
		cout << e<< '\n';
	}
	
}*/