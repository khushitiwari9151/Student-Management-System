#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

class Student
{
public:
    int id;
    string name;
    int age;
    string course;
};

void addStudent()
{
    Student s;

    ofstream file("students.txt", ios::app);

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, s.course);

    file << s.id << endl;
    file << s.name << endl;
    file << s.age << endl;
    file << s.course << endl;

    file.close();

    cout << "\nStudent Added Successfully!\n";
}

void displayStudents()
{
    Student s;

    ifstream file("students.txt");

    if (!file)
    {
        cout << "\nNo student records found!\n";
        return;
    }

    cout << "\n========== Student Records ==========\n";

    while (file >> s.id)
    {
        file.ignore();

        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.course);

        cout << "\nStudent ID : " << s.id;
        cout << "\nName       : " << s.name;
        cout << "\nAge        : " << s.age;
        cout << "\nCourse     : " << s.course;
        cout << "\n------------------------------------\n";
    }

    file.close();
}

void searchStudent()
{
    Student s;
    int searchId;
    bool found = false;

    ifstream file("students.txt");

    if (!file)
    {
        cout << "\nNo student records found!\n";
        return;
    }

    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    while (file >> s.id)
    {
        file.ignore();
        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.course);

        if (s.id == searchId)
        {
            cout << "\nStudent Found!\n";
            cout << "Student ID : " << s.id << endl;
            cout << "Name       : " << s.name << endl;
            cout << "Age        : " << s.age << endl;
            cout << "Course     : " << s.course << endl;

            found = true;
            break;
        }
    }

    file.close();

    if (!found)
    {
        cout << "\nStudent not found!\n";
    }
}

void updateStudent()
{
    Student s;
    int updateId;
    bool found = false;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    if (!file)
    {
        cout << "\nNo student records found!\n";
        return;
    }

    cout << "\nEnter Student ID to update: ";
    cin >> updateId;

    while (file >> s.id)
    {
        file.ignore();
        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.course);

        if (s.id == updateId)
        {
            found = true;

            cout << "\nEnter New Name: ";
            getline(cin >> ws, s.name);

            cout << "Enter New Age: ";
            cin >> s.age;

            cout << "Enter New Course: ";
            getline(cin >> ws, s.course);
        }

        temp << s.id << endl;
        temp << s.name << endl;
        temp << s.age << endl;
        temp << s.course << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent record updated successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

void deleteStudent()
{
    Student s;
    int deleteId;
    bool found = false;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    if (!file)
    {
        cout << "\nNo student records found!\n";
        return;
    }

    cout << "\nEnter Student ID to delete: ";
    cin >> deleteId;

    while (file >> s.id)
    {
        file.ignore();
        getline(file, s.name);

        file >> s.age;
        file.ignore();

        getline(file, s.course);

        if (s.id == deleteId)
        {
            found = true;
            continue;
        }

        temp << s.id << endl;
        temp << s.name << endl;
        temp << s.age << endl;
        temp << s.course << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent deleted successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "      Student Management System\n";
        cout << "========================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank you for using the program.\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}