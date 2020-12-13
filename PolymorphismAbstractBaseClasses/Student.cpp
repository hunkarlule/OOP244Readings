#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Student.h"
using namespace std;

namespace sdds
{
	Person::Person()
	{
		name[0] = '\0';
	}

	Person::Person(const char* nm)
	{
		strncpy(name, nm, NC);
		name[NC] = '\0';
	}

	void Person::display(ostream& os) const
	{
		os << name << ' ';
	}

	Student::Student()
	{
		no = 0;
		ng = 0;
	}

	Student::Student(int n)
	{
		float g[] = { 0.0f };
		*this = Student("", n, g, 0);
	}

	Student::Student(const char* nm, int sn, const float* g, int ng_) : Person(nm)
	{
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

	void Student::display(ostream& os) const
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
	iPerson* CreatePerson()
	{
		iPerson* p = nullptr;
		int type, no, ng;
		float grade[NG];
		char name[NC + 1];
		bool repeat;

		do
		{
			std::cout << "Type (0,1,2) : ";
			std::cin >> type;
			std::cin.ignore();
			repeat = false;

			switch (type)
			{
			case 0:
				break;
			case 1:
				std::cout << "Name: ";
				std::cin.getline(name, NC + 1);
				p = new Person(name);
				break;
			case 2:
				std::cout << "Name: ";
				std::cin.getline(name, NC + 1);
				std::cout << "Student Number : ";
				std::cin >> no;
				std::cout << "Number of Grades : ";
				std::cin >> ng;
				if (ng > NG) ng = NG;
				for (int i = 0; i < ng; i++)
				{
					std::cout << "Grade " << i + 1 << " : ";
					std::cin >> grade[i];
					std::cin.ignore();
				}
				p = new Student(name, no, grade, ng);
				break;
			default:
				repeat = true;
				std::cout << "Invalid type. Try again\n";
			}
		} while (repeat);

		return p;
	}
}
