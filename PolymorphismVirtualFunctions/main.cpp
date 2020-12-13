#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"

using namespace std;
using namespace sdds;

//void show(const Person& p)
//{
//	p.display(std::cout);
//	std::cout << std::endl;
//}

//Overriding Dynamic Dispatch
/* 
Polymorphic Objects

A polymorphic object is an object that can change its dynamic type throughout its lifetime.  
Its static type identifies the hierarchy of types to which the object belongs.  
Its dynamic type identifies the rule for interpreting the bit string in the region of memory currently allocated for the object.

 We specify the dynamic type of a polymorphic object by allocating memory dynamically using 
 the appropriate constructor from the inheritance hierarchy.

*/
void show(const Person& p) // this specify the static type of a polymorphic object as Person
{
	p.display(std::cout);
	std::cout << std::endl;
}

int main()
{
	/*
	In the main() function:

    p initially points to nothing (holds the null address).  The object's dynamic type is undefined. 
    after the first allocation, p points to a Person type (dynamic type). 
    after the second allocation, p points to a Second type (the new dynamic type). 

	The static and dynamic types are related to one another through the hierarchy. 

	Note that we only need one show() function to display both dynamic types. 

	p holds the address a polymorphic object throughout its lifetime.  That address may change with deallocations and fresh allocations of memory.  The dynamic type may be of any type in the Person hierarchy. 

	show() is a polymorphic function.  Its parameter receives an unmodifiable reference to any type in the Person hierarchy. 
	
	*/

	Person* p = nullptr; // this specify the static type of a polymorphic object as Person
	p = new Person("Jane Doe");
	show(*p);
	delete p;

	float g[] = { 89.4f, 67.8f, 45.5f };
	p = new Student("Harry", 1234, g, 3);
	show(*p);
	delete p;

	return 0;
}
/* 
Good design Tip:

It is good programming practice to dynamically dispatch the destruction of any object in an inheritance hierarchy as virtual.  If an object of a derived class acquires a resource, typically the destructor of that class releases the resource.  To ensure that any object in the hierarchy calls the destructor of its most derived class at destruction time, we declare the base class destructor virtual.  Since the destructor of any derived class automatically calls the destructor of its immediate base class, all destructors in the object's hierarchy will be called in turn.

Good design codes the destructor in a base class as virtual, even if no class is currently derived from that base class.  The presence of a virtual base class destructor ensures that the most derived destructor will be called if and when a class is derived from the base class without requiring an upgrade to the definition of the base class.

*/

/*
Reusability and Flexibility

Implementing inclusion polymorphism improves reusability and flexibility of code.

Virtual functions reduce code size considerably.  Our show() function works on references of any type within the Person hierarchy.  We only define member functions (display()) for those classes that require specialized processing.

Consider a client application that uses our hierarchy.  During the life cycle of the hierarchy, we may add several classes.  Our original client code, without any alteration, will selects the most derived version of the member function for each upgrade of the hierarchy.  We will only need to add client code to create objects of new derived classes.

Summary

	1. polymorphism refers to the multiplicity of logic associated with the same name.
	2. static type is the type of the object's hierarchy and is available at compile-time
	3. dynamic type is the type of the object referenced and may change with different calls to the same function
	4. early binding of a call to a member function's definition occurs at compile-time
	5. the keyword virtual on a member function's declaration specifies dynamic dispatch
	6. a polymorphic object's pointer type identifies the object's static type
	7. a polymorphic object's constructor identifies the object's dynamic type
	8. declare a base class destructor virtual even if there are no derived classes


*/
