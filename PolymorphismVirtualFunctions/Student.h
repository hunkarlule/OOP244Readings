#pragma once
#ifndef  SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#include <iostream>
namespace sdds
{
   /*
	Overriding Dynamic Dispatch

	To override dynamic dispatch with early binding, we resolve the scope explicitly: See main.cpp for more explanation adn example.
   */
    
    const int NC = 30;
    const int NG = 20;

    class Person
    {
        char name[NC + 1];
    public:
        Person();
        Person(const char*);
        //void display(std::ostream&) const;
        virtual void display(std::ostream&) const;
    };

    class Student : public Person
    {
        int no;
        float grade[NG];
        int ng;
    public:
        Student();
        Student(int);
        Student(const char*, int, const float*, int);
        void display(std::ostream&) const;
    };
}
#endif //!SDDS_STUDENT_H_