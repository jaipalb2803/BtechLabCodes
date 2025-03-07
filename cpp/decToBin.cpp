#include <bits/stdc++.h>
using namespace std;

// Main function.
int main()
{
    // Two numbers for which we want binary representation.
	int num1 = 10;
	int num2 = -21;
	
	bitset<8>  b1(num1);
	bitset<32> b2(num1);
	
	bitset<8>  b3(num2);
	bitset<32> b4(num2);
	
	cout << "8-bit Binary of num1: ";
	cout << b1 << endl;
	
	cout << "32-bit Binary of num1: ";
	cout << b2 << endl;
	
	cout << "8-bit Binary of num2: ";
	cout << b3 << endl;
	
	cout << "32-bit Binary of num2: ";
	cout << b4 << endl;
}
