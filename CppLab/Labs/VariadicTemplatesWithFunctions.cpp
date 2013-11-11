
#include "VariadicTemplatesWithFunctions.h"
#include <iostream>


template<typename T>
inline T recFunc(T value)
{
	if (std::is_floating_point<T>::value) {
		std::streamsize prev = std::cout.precision(2);
		std::cout << std::fixed;
		std::cout << " " << value << " |";
		std::cout << std::defaultfloat;
		std::cout.precision(prev);
	} else {
		std::cout << " " << value << " |";
	}
	return value;
}

template<typename T>
inline T recFunc(const char* value)
{
	std::cout << " \"" << value << "\"s |";
	return value;
}

template<typename T, typename... Targs>
T recFunc(T value, Targs... args)
{
	recFunc(value);
	
	recFunc(args...);
	return value;
}

template<typename... Targs>
void variadicArgsRun(Targs... args)
{
	std::cout << "::variadicArgsRun Args: ";
	
	recFunc(args...);
	
	std::cout << std::endl;
}
//---
template<typename... Args> inline void stubPass(Args&&...) {}
template<typename... Targs>
void variadicArgsRun2(Targs&&... args)
{
	std::cout << "::variadicArgsRun2 Args: ";
	
	stubPass( recFunc(args)... );
	
	std::cout << std::endl;
}
//---

// Enable_if test
template<typename T>
inline typename std::enable_if<std::is_floating_point<T>::value>::type
enableIfTestFunc(T value)
{
	std::cout << value << "f" << std::endl;
}

template<typename T>
inline typename std::enable_if<!std::is_floating_point<T>::value>::type
enableIfTestFunc(T value)
{
	std::cout << value << std::endl;
}
//---


void VariadicTemplatesWithFunctions::run() {
	std::cout << std::endl << "-- VariadicTemplatesWithFunctions::run" << std::endl;
	
	variadicArgsRun(1, 2.0f, 3.123f, 553.246f, "4");
	variadicArgsRun2(1, 2.0f, 3.123f, 553.246f, "4");
	
	std::cout << "enable_if test:" << std::endl;
	enableIfTestFunc(33.3f);
	enableIfTestFunc(44);
}
