#include "Student.h"
#include <iostream>
using namespace std;

Student::~Student()
{
	delete studentname;
	delete studentusername;
	delete gpa;
	delete major;
	delete groupID;
}

Student::Student()
{
}

Student::Student(string* studentname, string* studentusername, float* gpa, int* major, int* groupID)
{
	this->studentname = studentname;
	this->studentusername = studentusername;
	this->gpa = gpa;
	this->major = major;
	this->groupID = groupID;
}

void Student::print()
{
	cout << *studentname << ":\t" << *studentusername << "\t " << *gpa << "\t" << *major << "\t" << *groupID << endl;
}

string* Student::getStudentName()
{
	return studentname;
}

float* Student::getGPA()
{
	return gpa;
}

int* Student::getMajor()
{
	return major;
}

int* Student::getGroupID()
{
	return groupID;
}

int* Student::getGPARange()
{
	if (gpa != nullptr)
	{
		int* gparange = new int(*gpa / .5);

		if (*gparange == 8)
		{
			*gparange = 7;
		}

		return gparange;
	}

	else
	{
		return nullptr;
	}
}