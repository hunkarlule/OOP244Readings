#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Student.h"
using namespace std;
using namespace sdds;

int main()
{
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry(1234, gh, 3), backup;
    harry.display();
    harry += 78.23f;
    harry.display();

    ++harry;
    harry.display();

    backup = harry++;
    harry.display();
    backup.display();

    if (harry)
    {
        cout << "student harry is  true!" << endl;
    }
    else
    {
        cout << "student harry is false!" << endl;
    }

    // The first use converts 975 to the Student object harry.  The second use casts 428 to a Student object containing the number 428.  
    // Both objects hold empty grade lists.  
    Student hunkar(975), liran;
    hunkar.display();
    liran = (Student)428;
    liran.display();

    // Promotion
    // For the same result as the above cast, we may omit the cast operator and defer to the compiler promoting the int value 428 to a Student object before assigning the object to jane :
    // The compiler inserts code that creates a temporary Student object using the single-argument constructor.  The constructor receives the value 428 and initializes no to 428 and ng to 0.  Then, the assignment operator copies the temporary object to jane.  Finally, the compiler inserts code that destroys the temporary object removing it from memory. 
    Student  john(975), jane;
    john.display();
    // if we declare like this " explicit Student(int studentNo); " in the .h file then the second invocation in the example(nancy = 428) would generate a compiler error.  
    jane = 428; // promotes an int to a Student  
    jane.display();


    // if we declare like this " explicit Student(int studentNo); " in the .h file then the invocation in the example(Student tom = 1050;) would generate a compiler error. 
    Student tom = 1050;
    tom.display();

    cout << hunkar.operator int() << endl;
}