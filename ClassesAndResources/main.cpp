#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Student.h"
using namespace std;
using namespace sdds;

int main()
{
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry(1234, gh, 3);
	harry.display();

	// copy constructor example:
	// below line is compilation erro because we declared copy construtor like this "Student(const Student& student) =  delete;". So this prevents using copy constructor.
	Student hunkar(harry);
	hunkar.display();

	// copy assignment example:
	Student liran(1345);
	liran.display();

	// below line is compilation erro because we declared copy asignment operator like this "Student& operator=(const Student& studentToBeCopied) = delete;". So this prevents using copy assignment operator.
	liran = hunkar;
	liran.display();
	return 0;
}