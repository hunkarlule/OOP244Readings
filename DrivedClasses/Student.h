#pragma once
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#include "Person.h"

namespace sdds
{
    const int NG = 20;
	class Student : public Person
	{
        int no;
        float grade[NG];
        int ng;
    public:
        Student();
        Student(int);
        Student(int, const float*, int);
        void display(std::ostream& os) const;
	};
}
#endif //!SDDS_STUDENT_H_

