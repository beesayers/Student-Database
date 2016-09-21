#include "SLL.h"

int main()
{
	string* tempstudentname = nullptr;
	string* tempstudentusername = nullptr;
	string* input = new string;
	string* temp = new string;
	string tempinput;

	float* tempgpa = new float();

	int* tempmajor = new int();
	int* tempgroupID = new int();

	SLL* originalSLL = new SLL();
	SLL* gpaSLL = new SLL();
	SLL* majorSLL = new SLL();
	SLL* groupidSLL = new SLL();

	bool done = false;
	bool printdone = false;

    cout << "Welcome to the student database!" << endl;
	cout << "----------------------------------------------------------" << endl;

	do
	{
		
		cout << "Please choose from the following options: " << endl;
		cout << "\tTo add a student, enter \"add\"" << endl;
		cout << "\tTo remove a student, enter \"remove\"" << endl;
		cout << "\tTo print information for all students, enter \"print\"" << endl;
		getline(cin, *input);
		cout << "----------------------------------------------------------" << endl;

		if (*input == "add")
		{
			string name;
			string username;
			float gpa;
			int major;
			int group;

			cout << "Please enter student information: " << endl;

			cout << "Student name: ";
			getline(cin, name);
			tempstudentname = new string(name);				 // losing data without this

			cout << "Student username: ";
			getline(cin, username);
			tempstudentusername = new string(username);

			while (!done)
			{
				cout << "Student GPA: (0.00-4.00)" << endl;
				cin >> gpa;
				tempgpa = new float(gpa);

				if (gpa >= 0.0 && gpa <= 4.0)
				{
					done = true;
				}

				else
				{
					cout << "\nInvalid input! Please enter a valid value for student's gpa.\n" << endl;
				}
			}
			done = false;

			while (!done)
			{
				cout << "Student major: (0, 100, 200, etc.)" << endl;
				cin >> major;
				tempmajor = new int(major);

				if (major % 100 != 0)
				{
					cout << "\nInvalid input! Please enter a valid value for student's major.\n" << endl;
				}

				else if (major % 100 == 0)
				{
					done = true;
				}
			}
			done = false;

			cout << "Student group ID: (0, 1, 2, etc.)" << endl;
			cin >> group;
			tempgroupID = new int(group);

			Student* newStudent = new Student(tempstudentname, tempstudentusername, tempgpa, tempmajor, tempgroupID);
			Student* newGPAStudent = new Student(tempstudentname, tempstudentusername, tempgpa, tempmajor, tempgroupID);
			Student* newMajorStudent = new Student(tempstudentname, tempstudentusername, tempgpa, tempmajor, tempgroupID);
			Student* newGroupIDStudent = new Student(tempstudentname, tempstudentusername, tempgpa, tempmajor, tempgroupID);
			
			originalSLL->add(newStudent);
			gpaSLL->addByGPA(newGPAStudent);
			majorSLL->addByMajor(newMajorStudent);
			groupidSLL->addByGroupID(newGroupIDStudent);

			cin.ignore();
			cout << "----------------------------------------------------------" << endl;
		}

		if (*input == "remove")
		{
			cout << "Please enter the name of the student you would like to delete: " << endl;
			getline(cin, tempinput);
			temp = new string(tempinput);

			originalSLL->deleteStudent(temp);
			gpaSLL->deleteInOrder(temp);
			majorSLL->deleteInOrder(temp);
			groupidSLL->deleteInOrder(temp);
			cout << "----------------------------------------------------------" << endl;
		}

		if (*input == "print") 						// Print a list of students by gpa, by major, or by group ID
		{
			float gpa;
			int major;
			int group;

			do
			{
				cout << "If you would like to print students in order by gpa, please type: \t gpa" << endl;
				cout << "If you would like to print students in order by major, please type: \t major" << endl;
				cout << "If you would like to print students in order by group ID, please type: \t group" << endl;
				getline(cin, tempinput);
				temp = new string(tempinput);
				cout << "----------------------------------------------------------" << endl;

				if (!(*temp == "gpa" || *temp == "major" || *temp == "group"))
				{
					cout << "\nYour input was invalid, please select from the following options:" << endl;
					cout << "----------------------------------------------------------" << endl;
				}

				else if (*temp == "gpa")				// print by gpa
				{
					cout << "Please enter a gpa within the range you would like to print (4.0 <-> 3.5, 3.49 <-> 3.0, etc..)" << endl;
					cin >> gpa;
					if (gpa == 4)
					{
						gpa = 3.5;
					}
					tempmajor = new int(gpa/.5);
					
					gpaSLL->print(temp, tempmajor);
					printdone = true;
				}

				else if (*temp == "major")				// print by major
				{
					cout << "Please enter the major of the students you would like to print" << endl;
					cin >> major;
					tempmajor = new int(major);

					majorSLL->print(temp, tempmajor);
					printdone = true;
				}

				else if (*temp == "group")				// print by group ID
				{
					cout << "Please enter the group ID of the students you would like to print" << endl;
					cin >> major;
					tempmajor = new int(major);

					groupidSLL->print(temp, tempmajor);
					printdone = true;
				}

				cin.ignore();
			} while (!printdone);
			printdone = false;
			cout << "----------------------------------------------------------" << endl;
		}
	
		cout << "Would you like to perform another action? \nEnter \"No\" to terminate the program or enter anything else to continue" << endl;
		getline(cin, *temp);
		cout << "----------------------------------------------------------" << endl;
		if (*temp == "No" || *temp == "no")
		{
			done = true;
		}
	} while (!done);
	return 0;
}