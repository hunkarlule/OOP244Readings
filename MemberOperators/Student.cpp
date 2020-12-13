#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Student.h"
using namespace std;
namespace sdds
{
	void Student::set(int sn, const float* g, int ng_)
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
			no = 0;
			ng = 0;
		}
	}
	Student::Student()
	{
		no = 0;
		ng = 0;
	}

	Student::Student(int sn, const float* g, int ng_)
	{
		set(sn, g, ng_);
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
	Student& Student::operator+=(float g)
	{
		if (no != 0 && ng < NG && g >= 0.0f && g <= 100.0f)
		{
			grade[ng++] = g;
		}

		return *this;
	}
	Student& Student::operator++()
	{
		for (int i = 0; i < ng; i++)
		{
			if (grade[i] < 99.0f)
			{
				grade[i] += 1.0f;
			}
		}
		return *this;
	}

	Student Student::operator++(int)
	{
		Student temp = *this;
		++(*this);
		return temp;
	}
	Student::operator bool() const
	{
		return no != 0;
	}

	Student::Student(int sn)
	{
		float g[] = { 0.0f };
		set(sn, g, 0);
	}

	Student::operator int()
	{
		return int(no);
	}


}
