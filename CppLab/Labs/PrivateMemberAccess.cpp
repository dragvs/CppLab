
#include "PrivateMemberAccess.h"
#include <iostream>
#include <string>


class ClosedClass
{
public:
	ClosedClass(const std::string data) : privateData(data) {}
	
	std::string getData() const { return privateData; }
	
	template<typename T>
	void someFunc(T value) {}
	
private:
	std::string privateData;
};

// Using a "hole" in a class interface
namespace {
	struct Y {};
}
template<>
void ClosedClass::someFunc(Y) {
	privateData += " - Modified!";
}

void PrivateMemberAccess::run()
{
	std::cout << std::endl << "-- PrivateMemberAccess::run" << std::endl;
	
	ClosedClass closedObj("MyData");
	std::cout << "Before: " << closedObj.getData() << std::endl;
	closedObj.someFunc(Y());
	std::cout << "After: " << closedObj.getData() << std::endl;
}

