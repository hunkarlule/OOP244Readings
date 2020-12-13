#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Person.h"
using namespace std;
namespace sdds
{
	void Person::set(const char* personName)
	{
		strncpy(name, personName, NC);
		name[NC] = '\0';
	}

	void Person::displayName(std::ostream& os) const
	{
		os << name << ' ';
	}
}

