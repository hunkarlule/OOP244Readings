#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"

using namespace std;
using namespace sdds;

int main()
{
	/*
	Helper Operators

	Helper functions support the classes identified by their parameter types.  Each helper function is dedicated to the class that it supports.  The compiler binds a call to a helper function on the basis of its parameter type(s).  That is, the helper functions of a base class do not directly support classes derived from the supported base class.

	Example

	Let us upgrade our Student class to include overloads of the insertion and extraction operators for both base and derived classes.  The header file contains:
	*/
    
	Person jane;
	Student harry;

	std::cin >> jane;
	std::cin >> harry;
	std::cout << jane << std::endl;
	std::cout << harry << std::endl;

    return 0;
}

/*

Summary

	1. a member function of a derived class shadows an identically named member function of a base class
	2. a derived class does not inherit the destructor, assignment operators or helper functions of a base class
	3. a derived class does not by default inherit the constructor of a base class, but we may add syntax to allow inheritance where the derived class constructor does not contain logic to set its instance variables
	4. constructors in an inheritance hierarchy execute in order from the base class to the derived class
	5. destructors in an inheritance hierarchy execute in order from the derived class to the base class



*/