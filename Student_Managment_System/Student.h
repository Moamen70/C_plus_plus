#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;
enum year
{Freashmen = 1,Semaphore,Junior,Senior1,Senior2 };

class Student
{
private:
	string name;
	int id;
	int age;
	float GPA;
	int level;
	
public:
	static int count, idCount;
	Student(string name, int age, float GPA);

	
	// Getters
	int getId() const;
	string getName() const;
	int getAge() const;
	float getGPA() const;

	// Setters
	void setName(string& name);
	void setAge(int& age);
	void setGPA(float& grade);
};

void addStudent(vector<Student>& students) ;
void viewAllStudents(vector<Student>& students);
void searchByName(vector<Student>& students);
void searchById(vector<Student>& students);
//void updateStudent();
void deleteStudent(vector<Student>& students);
int getStudentsNumber();

