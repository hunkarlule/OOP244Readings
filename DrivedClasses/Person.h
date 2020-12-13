#pragma once
#ifndef SDDS_PERSON_H_
#define SDDS_PERSON_H_
#include<iostream>
namespace sdds
{
	const int NC = 30;

	class Person
	{
		char name[NC + 1];

	public:
		void set(const char* n);

		/*
		Access
		The C++ language supports three modifiers for granting access to the members of class:

			private - bars all access
			protected - limits access to derived classes only
			public - unlimited access
		Since the data member of the Person class is private, the member functions of our Student class and the client code cannot access that data member.
		Since the member functions of the Person and Student classes are public, the main() function can access all of them.

		Limiting Access to Derived Classes:
		 The keyword protected limits access to members of a derived class.

		For example, let us limit access to displayName() to classes derived for the Person class.  Then, the main() function cannot call
		this member function and we must call it directly from Student::display().  The header file limits the access:
		*/
	protected:
		void displayName(std::ostream& os) const;

	};
}
#endif //!SDDS_PERSON_H_
