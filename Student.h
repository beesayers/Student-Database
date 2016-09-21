#ifndef STUDENT_H_
#define STUDENT_H_

#include <String.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student
{
public:
	Student();
	~Student();
	Student(string* studentname, string* studentusername, float* gpa, int* major, int* groupID);
	void print();
	string* getStudentName();
	float* getGPA();
	int* getMajor();
	int* getGroupID();
	int* getGPARange();

private:
	string* studentname;
	string* studentusername;
	float* gpa;
	int* major;
	int* groupID;
};

#endif