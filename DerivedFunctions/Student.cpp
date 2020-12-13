#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Student.h"
using namespace std;

namespace sdds
{
	Person::Person()
	{
		cout << "Person()" << endl;
		name[0] = '\0';
	}
	Person::Person(const char* name)
	{
		cout << "Person::set(const char*)" << endl;
		strncpy(this->name, name, NC);
		this->name[NC] = '\0';
	}
	Person::~Person()
	{
		cout << "Leaving " << name << endl;
	}
	//void Person::set(const char* n)
	//{
	//	cout << "Person::set(const char*)" << endl;
	//	strncpy(name, n, NC);
	//	name[NC] = '\0';
	//}

	void Person::display(std::ostream& os) const
	{
		os << name << ' ';
	}

	void Person::display(std::ostream& os, const char* msg) const
	{
		os << msg << name << ' ';
	}

	Student::Student()
	{
		cout << "Student()" << endl;
		no = 0;
		ng = 0;
	}

	Student::Student(int n)
	{
		cout << "Student(int)" << endl;
		float g[] = { 0.0f };
		*this = Student("", n, g, 0);
	}

	Student::Student(const char* name, int sn, const float* g, int ng_) : Person(name)
	{
		cout << "Student(int, const float*, int)" << endl;
		bool valid = sn > 0 && g != nullptr && ng_ >= 0;
		if (valid)
			for (int i = 0; i < ng_ && valid; i++)
				valid = g[i] >= 0.0f && g[i] <= 100.0f;

		if (valid)
		{
			// accept the client's data
			no = sn;
			ng = ng_ < NG ? ng_ : NG;
			for (int i = 0; i < ng; i++)
				grade[i] = g[i];
		}
		else
		{
			*this = Student();
		}
	}

	//Student::Student(int sn, const float* g, int ng_)
	//{
	//	cout << "Student(int, const float*, int)" << endl;
	//	bool valid = sn > 0 && g != nullptr && ng_ >= 0;
	//	if (valid)
	//		for (int i = 0; i < ng_ && valid; i++)
	//			valid = g[i] >= 0.0f && g[i] <= 100.0f;

	//	if (valid)
	//	{
	//		// accept the client's data
	//		no = sn;
	//		ng = ng_ < NG ? ng_ : NG;
	//		for (int i = 0; i < ng; i++)
	//			grade[i] = g[i];
	//	}
	//	else
	//	{
	//		*this = Student();
	//	}
	//}

	Student::~Student()
	{
		cout << "\nLeaving " << no << endl;
	}

	void Student::read(std::istream& is)
	{
		char name[NC + 1]; // will hold the student's name
		int no;            // will hold the student's number
		int ng;            // will hold the number of grades
		float grade[NG];   // will hold the grades

		std::cout << "Name: ";
		is.getline(name, NC + 1);
		cout << "Student Number : ";
		is >> no;
		cout << "Number of Grades : ";
		is >> ng;
		if (ng > NG) ng = NG;
		for (int i = 0; i < ng; i++)
		{
			cout << "Grade " << i + 1 << " : ";
			is >> grade[i];
		}

		// construct a temporary Student
		Student temp(name, no, grade, ng);
		// if data is valid, the temporary object into the current object 
		if (temp.no != 0)
			*this = temp;
	}

	/*
	By calling Person::display() within Student::display(), we hide the hierarchy from the client code.  The main() function is hierarchy agnostic. 
	*/
	void Student::display(std::ostream& os) const
	{
		if (no > 0)
		{
			Person::display(os);
			os << no << ":\n";
			os.setf(ios::fixed);
			os.precision(2);
			for (int i = 0; i < ng; i++)
			{
				os.width(6);
				os << grade[i] << endl;
			}
			os.unsetf(ios::fixed);
			os.precision(6);
		}
		else
		{
			os << "no data available" << endl;
		}
	}
	std::istream& operator>>(std::istream& is, Person& p)
	{
		char name[NC + 1];
		cout << "Name: ";
		is.getline(name, NC + 1);
		p = Person(name);
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Person& p)
	{
		p.display(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Student& s)
	{
		s.read(is);
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const Student& s)
	{
		s.display(os);
		return os;
	}

}
