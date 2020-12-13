#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Student.h"
using namespace std;
namespace sdds
{
	// we call this init function both in copy constructor and copy assignment operator.
	void Student::init(const Student& sourceStudent)
	{
		no = sourceStudent.no;
		ng = sourceStudent.ng;
		if (sourceStudent.grade != nullptr)
		{
			grade = new float[ng];
			for (int i = 0; i < ng; i++)
				grade[i] = sourceStudent.grade[i];
		}
		else
		{
			grade = nullptr;
		}

	}

	Student::Student()
	{
		no = 0;
		ng = 0;
		grade = nullptr;
	}

	Student::Student(int sn, const float* g, int ng_)
	{
		bool valid = sn > 0 && g != nullptr && ng_ >= 0;
		if (valid)
		{
			for (int i = 0; i < ng_ && valid; i++)
			{
				valid = g[i] >= 0.0f && g[i] <= 100.0f;
			}
		}

		if (valid)
		{
			no = sn;
			ng = ng_;
			if (ng > 0)
			{
				grade = new float[ng];
				for (int i = 0; i < ng; i++)
				{
					grade[i] = g[i];
				}
			}
			else
			{
				grade = nullptr;
			}
		}
		else
		{
			grade = nullptr;
			*this = Student();	
		}
	}

	Student::~Student()
	{
		delete[] grade;
	}

	void Student::display() const
	{
		if (no > 0)
		{
			cout << no << ":\n";
			cout.setf(ios::fixed);
			cout.precision(2);
			for (int i = 0; i < ng; i++)
			{
				cout.width(6);
				cout << grade[i] << endl;
			}
			cout.unsetf(ios::fixed);
			cout.precision(6);
		}
		else
		{
			cout << "no data available" << endl;
		}
	}

	Student::Student(int sn)
	{
		float g[] = { 0.0f };
		grade = nullptr;
		*this = Student(sn, g, 0);

	}
}
