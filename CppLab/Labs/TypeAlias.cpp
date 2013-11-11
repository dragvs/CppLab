
#include "TypeAlias.h"
#include <iostream>

// --
using yes = char[1];
using no = char[2];

// --
template<typename T>
using TFunc = void (*)(T);

// --
class Employee {
public:
	void doSomething(int smth) {
		std::cout << "Employee::doSomething " << smth << std::endl;
	};
};
using TEmployeeFunc = void (Employee::*)(int);


template<typename T>
void testFunc(T value) {
	std::cout << "::testFunc " << value << std::endl;
}

void TypeAlias::run() {
	std::cout << std::endl << "-- TypeAlias::run" << std::endl;
	
	std::cout << "Size of YES: " << sizeof(yes) << std::endl;
	std::cout << "Size of NO: " << sizeof(no) << std::endl;
	
	testFunc(0);
	
	TFunc<float> func = testFunc;
	func(11);
	
	TEmployeeFunc doFunc = &Employee::doSomething;
	Employee* employee = new Employee;
	(employee->*doFunc)(22);
}
