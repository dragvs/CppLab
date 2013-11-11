
#include "OperatorNew.h"
#include <iostream>
#include <new>

//#define REPLACE_GLOBAL

struct MemData {
	int stubData;
};
struct Error {
	int data;
};

//

#ifdef REPLACE_GLOBAL
void* operator new(size_t size) throw(std::bad_alloc) {
	std::cout << "::new(size_t) size: " << size << std::endl;
	return malloc(size);
}

// NB We can use this only directly via 'operator new(size, memData)'
// Custom 'operator new' overload
void* operator new(size_t size, const MemData& memData) throw(std::bad_alloc) {
	std::cout << "::new(size_t, MemData&) size: " << size << ", memData: " << memData.stubData << std::endl;
	return malloc(size);
}

// No-throwing overload
void* operator new(size_t size, const std::nothrow_t& nothrow) throw() {
	std::cout << "::new(size_t, nothrow_t&) size: " << size << std::endl;
	return malloc(size);
}

// NB Placement new - cannot be overloaded
//void* operator new(size_t size, void* ptr) throw();

void operator delete(void* ptr) throw() {
	std::cout << "::delete(void*) ptr: " << ptr << std::endl;
	free(ptr);
}
// NB will be called automatically if .ctor fails in 'new(std::nothrow) T()' statement
void operator delete(void* ptr, const std::nothrow_t& nothrow_constant) throw() {
	std::cout << "::delete(void*, nothrow_t&) ptr: " << ptr << std::endl;
	free(ptr);
}
// NB Placement delete - cannot be overloaded, lib implementation does nothing
//void operator delete(void* ptr, void* voidptr2) throw();

#endif //REPLACE_GLOBAL

//

// NB Empty class has at least 1 byte size
// NB Comment out any of the SomeClass 'operator new' to get compil. error for corresponding new statement
class SomeClass {
public:
	SomeClass() = default;
	explicit SomeClass(int err) {
		throw Error({err});
	}
	
	static void* operator new(size_t size) throw(std::bad_alloc) {
		std::cout << "SomeClass::new(size_t) size: " << size << std::endl;
		return ::operator new(size);
	}
	
	// Custom 'operator new' overload
	static void* operator new(size_t size, const MemData& memData) throw(std::bad_alloc) {
		std::cout << "SomeClass::new(size_t, MemData&) size: " << size << ", memData: " << memData.stubData << std::endl;
		
#ifdef REPLACE_GLOBAL
		return ::operator new(size, memData);
#else
		return ::operator new(size);
#endif
	}
	
	// No-throwing overload
	static void* operator new(size_t size, const std::nothrow_t& nothrow) throw() {
		std::cout << "SomeClass::new(size_t, nothrow_t&) size: " << size << std::endl;
		return ::operator new(size, nothrow);
	}
	
	// Placement new
	static void* operator new(size_t size, void* ptr) throw() {
		std::cout << "SomeClass::new(size_t, void*) size: " << size << ", ptr: " << ptr << std::endl;
		return ptr; // or call ::operator new(size, ptr);
	}
	
	// DELETE
	
	static void operator delete(void* ptr) throw() {
		std::cout << "SomeClass::delete(void*) ptr: " << ptr << std::endl;
		::operator delete(ptr);
	}
	// NB will be called automatically if .ctor fails in 'new(std::nothrow) SomeClass()' statement
	static void operator delete(void* ptr, const std::nothrow_t& nothrow) throw() {
		std::cout << "SomeClass::delete(void*, nothrow_t&) ptr: " << ptr << std::endl;
		::operator delete(ptr, nothrow);
	}
	static void operator delete(void* ptr, void* voidptr2) throw() {
		std::cout << "SomeClass::delete(void*, void*) ptr: " << ptr << std::endl;
		::operator delete(ptr, voidptr2);
	}
};


void OperatorNew::run()
{
	std::cout << std::endl << "-- OperatorNew::run" << std::endl;
	
	using Ptr = std::unique_ptr<SomeClass>;
	
	auto obj1 = Ptr(new SomeClass());
	
	MemData memData({57});
	auto obj2 = Ptr(new (memData) SomeClass());
	
	auto obj3 = Ptr(new (std::nothrow) SomeClass());
	
	std::cout << "\nPlacement new:\n";
	void* buff = ::operator new(sizeof(SomeClass));
	auto obj4 = new (buff) SomeClass();
	obj4->~SomeClass();
	::operator delete(buff);
	
	std::cout << "\nThrowing .ctor with new:\n";
	try {
		auto obj5 = Ptr(new (std::nothrow) SomeClass(78));
	} catch(const Error& err) {
		std::cout << "Error caught: " << err.data << std::endl;
	}
	
	std::cout << "-- OperatorNew::run return" << std::endl;
}

