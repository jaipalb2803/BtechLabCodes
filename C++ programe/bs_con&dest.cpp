#include <iostream>

using namespace std;
class Department {

  public:
    Department() {
      
      cout << "Constructor Invoked for Department class" << endl;
    }
    
    ~Department() {
      cout << "Destructor Invoked for Department class" << endl;
    }
};
class Employee {

  public:
    Employee() {
      cout << "Constructor Invoked for Employee class" << endl;
    }
    
    ~Employee() {
      cout << "Destructor Invoked for Employee class" << endl;
    }
};
int main(void) {
 
  Department d1; 
 
  Employee e2; 
  return 0;
} 
