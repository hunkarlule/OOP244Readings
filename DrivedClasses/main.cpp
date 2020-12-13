#define _CRT_SECURE_NO_WARNINIGS
#include<iostream>
#include<cstring>
#include"Student.h"

using namespace std;
using namespace sdds;

int main()
{
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry(1234, gh, 3);
	harry.set("Harry"); // iherited from person class
	//harry.displayName(cout); // inherited from person class
	harry.display(cout); // not inherited. it belongs to stundent class
	return 0;
}

//Good design tips & Summary:
/*
Avoid Granting Protected Access to Data Members

Granting data members protected access introduces a security hole.If a derived class has protected access to any data member of its base class, any member function of the derived class can circumvent any validation procedure in the base class.If the base class in the above example granted client code access to the person data member, we could change its contents from our Student class to a string of more than NC characters, which would probably break our Student object.

Good Design Tip

Granting protected access to any data member exposes that member to potential corruptionand is considered poor design.A protected read - only query is a preferable alternative to protected access to a data member.The query does not allow any modification of the value in the data member.

Summary

inheritance is a hierarchical relationship between classes.
a derived class inherits the entire structure of its base class
the access modifier protected grants access to member functions of the derived class
any member function of a derived class may access any protected or public member of its base class
keeping a data member private and accessing it through a protected query is good design
*/

