#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"

using namespace std;
using namespace sdds;

int main()
{
	iPerson* p = nullptr; 
	p = CreatePerson();
	
	p->display(std::cout);
	delete p;

	return 0;
}


