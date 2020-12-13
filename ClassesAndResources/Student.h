#pragma once
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
namespace sdds
{
	class Student
	{
		int no;
		float* grade;
		int ng;
		void init(const Student& sourceStudent);


	public:
		Student();
		Student(int);
		Student(int studentNo, const float* grades, int noOfGrades);
		~Student();
		void display() const;

		// Copies Prohibited
		// Certain class designs require prohibiting client code from copying or copy assigning any instance of a class.
		//To prohibit copying and /or copy assigning, we declare the copy constructorand /or the copy assignment operator as deleted members of our class
		Student(const Student& student) =  delete;
		Student& operator=(const Student& studentToBeCopied) = delete;



	};



}

#endif // !SDDS_STUDENT_H


