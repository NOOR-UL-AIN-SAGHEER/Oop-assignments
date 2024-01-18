#include <iostream>

using namespace std;



// Base class representing a user
class User
{
public:
    string name;
    int id;

    User(const string& Name, int ID) : name(Name), id(ID) {}

    virtual void displayDetails()
    {
       // cout << endl;
        cout << "User ID: " << id << ", Name: " << name << endl;
       // cout << endl;
    }
};

// Derived class representing a teacher
class Teacher : public User
{
public:
    string subject;

    Teacher(const string& name, int ID, const string& sub) : User(name, ID), subject(sub) {}

    void displayDetails() override
    {
       // cout << endl;
        User::displayDetails();
        cout << "Subject: " << subject << endl;
       // cout << endl;
    }
};

// Class representing a school class
class SchoolClass
{
public:
    string className;
    User* students[50]; // Assuming a maximum of 50 students per class
    Teacher* teacher;

    SchoolClass(const string& class_name, Teacher* teach) : className(class_name), teacher(teach)
    {
        for (int i = 0; i < 50; ++i)
        {
            students[i] = nullptr;
        }
    }

    void addStudent(User* student)
    {
        for (int i = 0; i < 50; ++i)
        {
            if (students[i] == nullptr)
            {
                students[i] = student;
                break;
            }
        }
    }

    void displayClassDetails()
    {
       // cout << endl;
        cout << "Class: " << className << endl;
        teacher->displayDetails();
        cout << "Students in Class:" << endl;
        for (int i = 0; i < 50 && students[i] != nullptr; ++i)
        {
            students[i]->displayDetails();
        }
        //cout << endl;
    }
};

// Derived class representing a student
class Student : public User
{
public:
    int grade;

    Student(const string& name, int ID, int Grade) : User(name, ID), grade(Grade) {}

    void displayDetails() override
    {
       // cout << endl;
        User::displayDetails();
        cout << "Grade: " << grade << endl;
        //cout << endl;
    }
};

// Class representing a school
class School
{
public:
    string schoolName;
    SchoolClass* classes[10]; // Assuming a maximum of 10 classes in a school

    School(const string& school_name) : schoolName(school_name)
    {
        for (int i = 0; i < 10; ++i)
        {
            classes[i] = nullptr;
        }
    }

    void addClass(SchoolClass* schoolClass)
    {
        for (int i = 0; i < 10; ++i)
        {
            if (classes[i] == nullptr)
            {
                classes[i] = schoolClass;
                break;
            }
        }
    }

    void displaySchoolDetails()
    {
       // cout << endl;
        cout << "School: " << schoolName << endl;
        cout << "Classes in School:" << endl;
        for (int i = 0; i < 10 && classes[i] != nullptr; ++i)
        {
            classes[i]->displayClassDetails();
        }
       // cout << endl;
    }
};

int main()
{
    // Creating users
    Student student1("Student1", 1, 9);
    Student student2("Student2", 2, 9);

    Teacher teacher1("Teacher1", 101, "Math");

    // Creating classes
    SchoolClass classA("ClassA", &teacher1);
    classA.addStudent(&student1);
    classA.addStudent(&student2);

    // Creating school
    School mySchool("MySchool");
    mySchool.addClass(&classA);
    // Creating users 
    Student student3("Student3", 5, 10);
    Student student4("Student4", 6, 10);

    Teacher teacher2("Teacher2", 102, "Physics");

    // Creating classes
    SchoolClass classB("ClassB", &teacher2);
    classB.addStudent(&student3);
    classB.addStudent(&student4);

    // Creating school for classB
    mySchool.addClass(&classB);

    // Displaying school details
    mySchool.displaySchoolDetails();

    return 0;
}
