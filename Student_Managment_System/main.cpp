
#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
	vector<Student>students;
	int choice;

	do {
		cout << "\n===== Student Management System =====\n";
		cout << "1. Add Student\n";
		cout << "2. Search Student By Id\n";
		cout << "3. Search Student By Name\n";
		cout << "4. Delete Student\n";
		cout << "5. View All Students\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: \n";
		while (!(cin >> choice)) {
			cin.clear();  // Clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore remaining input
		}

		switch (choice)
		{
		case 1:
			addStudent(students);
			break;
		case 2:
			searchById(students);
			break;
		case 3:
			searchByName(students);
			break;
		case 4:
			deleteStudent(students);
			break;
		case 5:
			viewAllStudents(students);
			break;
		case 6:
			cout << "Exitting The Program!\n";
			break;
		default:
			cout << "Invaild choice. Please choose a valid number! " << endl;
		}
	} while (choice != 6);
	
}


