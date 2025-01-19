#include "Student.h"


int Student::count = 0;
int Student::idCount = 0;


Student::Student(string name , int age , float GPA ) {
	this->setName(name);
	this->age = age;
	id = (1000 + idCount + 1);
	this->GPA = GPA;
}

void addStudent(vector<Student> &students) {
	string name;
	int age, year;
	float GPA;
	// Input student name
	cout << "Enter The Student Name:\n";
	cin.ignore();
	getline(cin, name);  // Get the full name

	// Input student age and validate
	cout << "Enter The Student Age:\n";
	while (!(cin >> age)) {
		cout << "Invalid age! Please enter a valid number for age: ";
		cin.clear();  // Clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore remaining input
	}

	// Input student level (year) and validate
	cout << "Enter The Student Level { 1 for Freshmen, 2 for Sophomore, 3 for Junior, 4 for Senior1, 5 for Senior2 }:\n";
	while (!(cin >> year) || year < 1 || year > 5) {
		cout << "Invalid level! Please enter a number between 1 and 5 for the level: ";
		cin.clear();  // Clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore remaining input
	}

	// Handle GPA based on the year
	if (year == 1) {
		GPA = 0;
		cout << "GPA is set to 0 for Freshman.\n";
	}
	else {
		cout << "Enter The Student GPA:\n";
		while (!(cin >> GPA) || GPA < 0 || GPA > 4) {
			cout << "Invalid GPA! Please enter a valid GPA between 0 and 4: ";
			cin.clear();  // Clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore remaining input
		}
	}

	// After numeric input, clear the input buffer before reading the name again
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This is crucial!
	students.emplace_back(name,age,GPA);
	cout << "Student Added Successfully!\n";
	Student::count++;
	Student::idCount++;
}

void viewAllStudents(vector<Student>& students) {
	if (students.empty()) {
		cout << "There Are No Students!";
	}
	else {
		int i = 1;
		for (const auto& student : students) {
			cout << "Student NO." << i << ":\nName: "
				<< student.getName() << "\tId: " << student.getId() << "\tAge: " << student.getAge() << "\t\tGPA: " << student.getGPA() << endl;
			i++;
		}
	}
}

void searchById(vector<Student>& students) {
	int id;
	if (students.empty()) {
		cout << "There Are No Students!";
	}
	else {
		cout << "Please enter the id of the student:\n";
		cin >> id;
		for (const auto& student : students) {
			if (student.getId() == id) {
				cout << "Student Found!" << "\nName: "
					<< student.getName() << "\tId: " << student.getId() << "\tAge: " << student.getAge() << "\tGPA: " << student.getGPA();
			}
			else {
				cout << "There is no student with this id!";
			}
		}
	}
}

void searchByName(vector<Student>& students) {
	string name;
	if (students.empty()) {
		cout << "There Are No Students!";
	}
	else {
		cout << "Please enter the name of the student:\n";
		cin.ignore();
		getline(cin, name);
		for (const auto& student : students) {
			if (student.getName() == name) {
				cout << "Student Found!" << "\nName: "
					<< student.getName() << "\tId: " << student.getId() << "\tAge: " << student.getAge() << "\tGPA: " << student.getGPA();
			}
			else {
				cout << "There is no student with this id!";
			}
		}
	}
}

//void deleteStudent(vector<Student>& students) {
//	int id;
//	if (students.empty()) {
//		cout << "There Are No Students To Delete!";
//	}
//	else {
//		cout << "Please enter the id of the student to delete:\n";
//		cin >> id;
//		int i = 0;
//		for (auto it = students.begin(); it != students.end(); ++it) {
//			if (it->getId() == id) {
//				students.erase(it);
//				Student::count--;
//			}
//			else {
//				cout << "There is no student with this id to delete!\n";
//			}
//			i++;
//		}
//	}
//}
void deleteStudent(vector<Student>& students) {
	if (students.empty()) {
		cout << "There are no students to delete!\n";
		return;
	}

	int id;
	cout << "Please enter the ID of the student to delete:\n";
	cin >> id;

	bool studentFound = false; // Flag to check if a student was found
	for (auto it = students.begin(); it != students.end();) {
		if (it->getId() == id) {
			students.erase(it); // Erase the student
			Student::count--;   // Update the count
			cout << "Student with ID " << id << " deleted successfully!\n";
			studentFound = true;
			break; // Exit the loop after deleting the student
		}
		else {
			++it; // Increment the iterator only if no deletion occurs
		}
	}

	if (!studentFound) {
		cout << "There is no student with this ID to delete!\n";
	}
}


int getStudentsNumber() {
	return Student::count;
}

// Getters
int Student::getId() const { return id; }
string Student::getName() const { return name; }
int Student::getAge() const { return age; }
float Student::getGPA() const { return GPA; }

// Setters
void Student::setName(string& name) { this->name = name; }
void Student::setAge(int& age) { this->age = age; }
void Student::setGPA(float& grade) { this->GPA = GPA; }


