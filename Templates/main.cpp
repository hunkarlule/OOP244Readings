#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*

Constrained Casts

Constrained casts improve type safety.  Type safety is an important feature of any strongly typed language.  Bypassing the type system introduces ambiguity to the language itself and is best avoided.  Casting a value from one type to another type circumvents the type system's type checking facilities.  It is good programming practice to implement casts only where absolutely unavoidable and localize them as much as possible.

C++ supports constrained type casting through template syntax using one of the following keywords:

	static_cast<Type>(expression)
	reinterpret_cast<Type>(expression)
	const_cast<Type>(expression)
	dynamic_cast<Type>(expression)

Type specifies the destination type.  expression refers to the value to be cast to the destination type.
*/

/*
Inherited Types

The dynamic_cast<Type>(expression) keyword converts the value of an expression from its type to another type within the same class hierarchy and performs some type checking.

*/
/*
Note that a static_cast works here and may produce the result shown on the right.  However, the Derived part of the object would then be incomplete.  static_cast does not check if the object is complete, leaving the responsibility to the programmer.

Note that if display() is declared virtual the output may be the same for both calls to display()
*/
class Base
{
public:
	void display() const
	{
		std::cout << "Base\n";
	}
};
class Derived : public Base
{
public:
	void display() const
	{
		std::cout << "Derived\n";
	}
};

// const_cast<Type>(expression)
int main()
{
	Base* b = new Base;
	Derived* d;


	d = static_cast<Derived*>(b); // OK
	//	d = dynamic_cast<Derived*>(b); // Fails- compile time error.
	//Because Base class doee not have any vitrual member function it mkae the Base class monomorphic. So that causes erro  at line (d = dynamic_cast<Derived*>(b);).

	b->display();
	d->display();

	delete d;

	return 0;
}
