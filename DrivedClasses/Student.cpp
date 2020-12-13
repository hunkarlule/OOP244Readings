#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Student.h"
using namespace std;
namespace sdds
{
	Student::Student()
	{
		no = 0;
		ng = 0;
	}

	sdds::Student::Student(int n)
	{
		float g[] = { 0.0f };
		*this = Student(n, g, 0);
	}

	sdds::Student::Student(int sn, const float* g, int ng_)
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
	// We refer to displayName() directly without any scope resolution as if this function is a member of our Student class.  
	void sdds::Student::display(std::ostream& os) const
	{
		if (no > 0)
		{
			displayName(os);
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
}