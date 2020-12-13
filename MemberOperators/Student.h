#pragma once
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
namespace sdds
{
	const int NG = 20;

	class Student
	{
		int no;
		float grade[NG];
		int ng;
		void set(int studentNo, const float* grades, int noOfGrades);

	public:
		Student();
		Student(int studentNo, const float* grades, int noOfGrades);
		void display() const;

		/*
		Binary Operators

		A binary operation consists of one operator and two operands.  In a binary member operator, the left operand is the current object and the member function takes one explicit parameter: the right operand.
		The declaration of a binary member operator takes the form

			return_type operator symbol (type [identifier])

		return_type is the type of the evaluated expression.  operator identifies the function as an operation.  symbol specifies the kind of operation.  type is the type of the right operand.  identifier is the right operand's name.
		*/
		// Let us overload the += operator for a float as the right operand, in order to add a single grade to a Student object:
		Student& operator+=(float g);

		/*
			Unary Operators

		A unary operation consists of one operator and one operand.  The left operand of a unary member operator is the current object.  The operator does not take any explicit parameters (with one exception - see post-fix operators below).
		The header for a unary member operator takes the form

			return_type operator symbol()

		return_type is the type of the evaluated expression.  operator identifies an operation.  symbol identifies the kind of operation.
		*/

		// Pre - Fix Operators
		// We overload the pre - fix increment / decrement operators to increment / decrement the current object and return a reference to its updated value.The header for a pre - fix operator takes the form: 
		//				Type & operator++() or Type & operator--()

		// Let us overload the pre-fix increment operator for our Student class so that a pre-fix expression increases all of the Student's grades by one mark, if possible:
		Student& operator++();

		// Post - Fix Operators
		// We overload the post - fix operators to increment / decrement the current object after returning its value.The header for a post - fix operator takes the form: 
		//				return_type operator++(int)  or  Type operator--(int)

		// The int type in the header distinguishes the post - fix operators from their pre - fix counterparts.

		// Let us overload the pre-fix increment operator for our Student class so that a pre-fix expression increases all of the Student's grades by one mark, if possible:
		Student operator++(int);


		// Type Conversion Operators

		// bool operator
		// Let us define a conversion operator that returns true if the Student object has valid data and false if the object is in a safe empty state.
		operator bool() const;

		// int operator
		operator int();

		// Cast Operator
		// C++ defines the casting operation for a class type in terms of a single - argument constructor.This overloaded constructor defines the rule for casting a value of its parameter type to the class type, as well as constructing an object from an argument of the parameter type.
		Student(int studentNo);
		// To prohibit the compiler from using a single-argument constructor for any implicit conversion, we declare that constructor explicit: 
		// explicit Student(int studentNo);
	};



}

#endif // !SDDS_STUDENT_H


