#pragma once
#ifndef  SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#include <iostream>
namespace sdds
{
	const int NC = 30;
	const int NG = 20;

	/*
	Helper Operators

	Helper functions support the classes identified by their parameter types.  Each helper function is dedicated to the class that it supports.  The compiler binds a call to a helper function on the basis of its parameter type(s).  That is, the helper functions of a base class do not directly support classes derived from the supported base class.

	Example

	Let us upgrade our Student class to include overloads of the insertion and extraction operators for both base and derived classes.  The header file contains:
	*/

	class Person
	{
		char name[NC + 1];

	public:
		Person();
		Person(const char* name);
		~Person();
		//void set(const char* n);
		void display(std::ostream& os) const;
		void display(std::ostream& os, const char* msg) const;
	};

	std::istream& operator>>(std::istream& istr, Person& person);
	std::ostream& operator<<(std::ostream& ostr, const Person& person);


	

	class Student : public Person
	{
		int no;
		float grade[NG];
		int ng;
	public:

		Student();
		Student(int);
		Student(const char*, int, const float*, int);
		//Student(int, const float*, int);
		~Student();
		void read(std::istream&);
		void display(std::ostream&) const;
		using Person::display;

	};
	std::istream& operator>>(std::istream& istr, Student& student);
	std::ostream& operator<<(std::ostream& ostr, const Student& student);
}

#endif //!SDDS_STUDENT_H_

