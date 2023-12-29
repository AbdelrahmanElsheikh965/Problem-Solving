#include <iostream>

using namespace std;
/*

    This problem is to get you familiar with virtual functions.
    Create three classes Person, Professor and Student. The class Person should have data members name and age.
    The classes Professor and Student should inherit from the class Person.

    The class Professor should have two integer members: publications and cur_id.
    There will be two member functions: getdata and putdata.
    The function getdata should get the input from the user: the name, age and publications of the professor.
    The function putdata should print the name, age, publications and the cur_id of the professor.

    The class Student should have two data members: marks, which is an array of size 6 and cur_id.
    It has two member functions: getdata and putdata.
    The function getdata should get the input from the user: the name, age, and the marks of the student in 6 subjects.
    The function putdata should print the name, age, sum of the marks and the cur_id of the student.

    For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from 1.
    Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.
    Note: Expand the main function to look at how the input is being handled.

*/

class Person        
{
    protected:
        string name;
        int age;
    public:
        virtual void getdata() = 0;     // abstract method
        virtual void putdata() = 0;
};


class Student : public Person
{
    public:
        int* marks = (int* )malloc(sizeof(int) * 6);
        int* sum   = (int* )malloc(sizeof(int));
        static int cur_id;
        int My_cur_id;

        Student()
        {
            My_cur_id = cur_id;
            cur_id++;
        }

        int* receiveAndSumMarks(int * marks_ptr, int* sum_ptr);

        void getdata()
        {
            cin>> name >> age;
            name         = name;
            age          = age;
            receiveAndSumMarks(marks, sum);
        }

        void putdata()
        {
            cout << name <<" "<< age <<" "<< *sum << " "<< My_cur_id << endl;
        }

};

int Student::cur_id   = 1;

int* Student::receiveAndSumMarks(int * marks_ptr, int* sum)
{
    int* new_marks  = (int* )malloc(sizeof(int) * 6);
    new_marks       = marks_ptr;

    int temp = 0;

    for(int i = 0; i < 6; i++)
    {
        scanf("%i", marks_ptr);
        temp += *marks_ptr;
        marks_ptr++;
    }
    *sum = temp;

    return new_marks;   // pointing to the first element.
}


class Professor : public Person
{
    public:
      int  publications;
      static int cur_id;
      int My_cur_id;

        Professor()
        {
            My_cur_id = cur_id;
            cur_id++;
        }

        void getdata()
        {
            cin>> name >> age >> publications;
            name         = name;
            age          = age;
            publications = publications;
        }
        void putdata()
        {
            cout << name << " " << age << " " << publications << " "<< My_cur_id << endl;
        }
};

int Professor::cur_id = 1;

int main_train()
{
    int n = 0;
    Professor* p[5];

    while(n <5)
    {
        p[n] = new Professor;
        p[n]->getdata();
        p[n]->putdata();
        n++;
    }
    p[3]->getdata();    // out of scope


    return 0;
}
