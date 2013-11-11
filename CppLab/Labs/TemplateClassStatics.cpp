
#include "TemplateClassStatics.h"
#include <iostream>
#include <string>


class DataClass
{
public:
	DataClass(const std::string& _id) : id(_id) {
		std::cout << "\tDataClass.ctor id: [" << id << "]" << std::endl;
	}
	
	const std::string& GetId() const { return id; }
	
private:
	DataClass() = delete;
	
	std::string id;
};

template<typename T, int idx>
class TemplateClass
{
public:
	static const DataClass classData;
	
	static void staticFunc() {
		static DataClass funcData(std::string("TemplateClass<T, ") + std::to_string(idx) + "> static func data");
		std::cout << "\tTemplateClass<T, " << idx << ">::staticFunc called" << std::endl;
	}
};

template<typename T, int idx>
const DataClass TemplateClass<T, idx>::classData = DataClass(std::string("TemplateClass<T, ") + std::to_string(idx) + "> static class data");


void TemplateClassStatics::run()
{
	std::cout << std::endl << "-- TemplateClassStatics::run" << std::endl;
	
	// Every template class instance has it's own static data inside a function scope.
	std::cout << "Static func data:\n";
	TemplateClass<int, 11>::staticFunc();
	TemplateClass<int, 22>::staticFunc();
	
	// Member static wouldn't be inited without any reference to it, try to comment any.
	// Otherwise initialization occurs at the startup.
	std::cout << "\nStatic class member\n";
	std::cout << "\t" << TemplateClass<int, 33>::classData.GetId() << std::endl;
	std::cout << "\t" << TemplateClass<int, 44>::classData.GetId() << std::endl;
}
