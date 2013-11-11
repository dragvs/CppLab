
#include "OverloadingWithTemplateSpec.h"
#include <iostream>


template<typename T>
void f(T value)
{
	std::cout << "::f<T>(T) " << value << std::endl;
}

template<>
void f<int*>(int* value)
{
	std::cout << "::f<int*>(int*) " << *value << std::endl;
}

template<typename T>
void f(T* value)
{
	std::cout << "::f<T>(T*) " << *value << std::endl;
}

void OverloadingWithTemplateSpec::run()
{
	std::cout << std::endl << "-- OverloadingWithTemplateSpec::run" << std::endl;
	
	// Template specializations aren't involved in primary function overload resolution
	std::unique_ptr<int> value(new int(33));
	int* temp = value.get();
	f(temp);
}