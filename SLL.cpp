#include "SLL.h"

SLL::SLL()
{
	head = nullptr;
	skipprevious = nullptr;
	tail = nullptr;
}

SLL::~SLL()
{
}

void SLL::add(Student* setStudent)
{
	Student* tempStudent = new Student(*setStudent);
	Node* tempnode = new Node(tempStudent, nullptr);		//set new node's data to the student entered

	if (head == nullptr)
	{
		head = tempnode;								//set head node to first node
		tail = head;
	}

	else
	{
		tail->setNext(tempnode);						//if tail does not point to a node, point it to the new node currently being added
		tail = tempnode;
	}
}

void SLL::addByGPA(Student* setStudent)
{
	Node* tempnode = new Node(setStudent, nullptr);
	Node* iteratenode = head;
	Node* previous = head;
	skipprevious = head; 
	bool done = false;

	if (head == nullptr)
	{
		head = tempnode;
		done = true;
	}

	while (!done)
	{
		if (*iteratenode->getData()->getGPARange() == *setStudent->getGPARange())	
		{								// if current students GPA is within our range
			if (*iteratenode->getData()->getGPA() < *setStudent->getGPA())		
			{								// if current gpa is less than ours
				if (head = iteratenode)
				{
					head = tempnode;
				}

				if (skipprevious->getSkipNext() == iteratenode)
				{								// if skipprevious->skipNext points to current
					skipprevious->setSkipNext(tempnode);
				}

				if (iteratenode->getSkipNext() != nullptr)
				{								// if current->skipNext does not point to null pointer
					tempnode->setSkipNext(iteratenode->getSkipNext());
					iteratenode->setSkipNext(nullptr);
				}

				if (previous != iteratenode)
				{								// if previous does not equal current
					previous->setNext(tempnode);
				}

				tempnode->setNext(iteratenode);
				done = true;
			}

			else if (*iteratenode->getData()->getGPA() > *setStudent->getGPA() || *iteratenode->getData()->getGPA() == *setStudent->getGPA())
			{								// if current gpa is more than or equal to ours
				if (iteratenode->getNext() == nullptr)
				{								// if current->next points to null pointer
					iteratenode->setNext(tempnode);
				}

				else if (*iteratenode->getNext()->getData()->getGPA() < *setStudent->getGPA())
				{								// if next's gpa is less than ours
					tempnode->setNext(iteratenode->getNext());
					iteratenode->setNext(tempnode);
				}
				done = true;
			}
		}

		else if (*iteratenode->getData()->getGPARange() > *setStudent->getGPARange())	
		{									// if current gpa range is higher than ours
			if (iteratenode->getNext() == nullptr)
			{									// if next points to null pointer
				iteratenode->setNext(tempnode);
				skipprevious->setSkipNext(tempnode);
				done = true;
			}

			else if (*iteratenode->getNext()->getData()->getGPARange() < *setStudent->getGPARange())
			{									// if next's gpa range is less than ours
				tempnode->setNext(iteratenode->getNext());
				tempnode->setSkipNext(skipprevious->getSkipNext());
				iteratenode->setNext(tempnode);
				skipprevious->setSkipNext(tempnode);
				done = true;
			}

		}

		else if (*iteratenode->getData()->getGPARange() < *setStudent->getGPARange())	
		{								// if current student's gpa range is lower than ours
			if (previous == iteratenode)
			{
				head = tempnode;
				tempnode->setNext(iteratenode);
			}
			
			if (skipprevious->getSkipNext() == nullptr)
			{
				tempnode->setSkipNext(iteratenode);
				done = true;
			}
		}

		if (skipprevious->getSkipNext() == iteratenode)
		{
			skipprevious = iteratenode;
		}

		if (iteratenode->getNext() != nullptr)
		{
			previous = iteratenode;
			iteratenode = iteratenode->getNext();
		}
	}
}

void SLL::addByMajor(Student* setStudent)
{
	Node* tempnode = new Node(setStudent, nullptr);
	Node* iteratenode = head;
	Node* previous = head;
	skipprevious = head;
	bool done = false;

	if (head == nullptr)
	{
		head = tempnode;
		done = true;
	}

	while (!done)
	{
		if (*iteratenode->getData()->getMajor() == *tempnode->getData()->getMajor())
		{									// if current major is equal to ours
			if (iteratenode->getNext() == nullptr)
			{								// if our major is the highest in the list
				iteratenode->setNext(tempnode);
				done = true;
			}

			else if (*iteratenode->getNext()->getData()->getMajor() != *tempnode->getData()->getMajor())
			{
				tempnode->setNext(iteratenode->getNext());
				iteratenode->setNext(tempnode);
				done = true;
			}
		}

		else if (*iteratenode->getData()->getMajor() > *tempnode->getData()->getMajor())
		{									// if current major is more than ours
			if (iteratenode == head)
			{
				head = tempnode;
				skipprevious = head;
			}

			else
			{
				previous->setNext(tempnode);
			}

			skipprevious->setSkipNext(tempnode);
			tempnode->setNext(iteratenode);
			tempnode->setSkipNext(iteratenode);
			done = true;
		}

		else if (*iteratenode->getData()->getMajor() < *tempnode->getData()->getMajor())
		{									// if current major is less than ours
			if (iteratenode->getNext() == nullptr)
			{									// if our major is the highest in the list
				tempnode->setNext(iteratenode->getNext());
				iteratenode->setNext(tempnode);
				skipprevious->setSkipNext(tempnode);
				done = true;
			}

			else if (*iteratenode->getNext()->getData()->getMajor() > *tempnode->getData()->getMajor())
			{									// if next's major is more than ours
				tempnode->setNext(iteratenode->getNext());
				iteratenode->setNext(tempnode);
				tempnode->setSkipNext(skipprevious->getSkipNext());
				skipprevious->setSkipNext(tempnode);
				done = true;
			}
		}

		if (skipprevious->getSkipNext() == iteratenode)
		{
			skipprevious = iteratenode;
		}

		if (!done)
		{
			previous = iteratenode;
			iteratenode = iteratenode->getNext();
		}

		else if (done)
		{
			skipprevious = head;
		}
	}
}

void SLL::addByGroupID(Student* setStudent)
{
	Node* tempnode = new Node(setStudent, nullptr);
	Node* iteratenode = head;
	Node* previous = head;
	skipprevious = head;
	bool done = false;

	if (head == nullptr)
	{
		head = tempnode;
		done = true;
	}

	while (!done)
	{
		if (*iteratenode->getData()->getGroupID() == *tempnode->getData()->getGroupID())
		{									// if current major is equal to ours
			if (iteratenode->getNext() == nullptr)
			{								// if our major is the highest in the list
				iteratenode->setNext(tempnode);
				done = true;
			}

			else if (*iteratenode->getNext()->getData()->getGroupID() != *tempnode->getData()->getGroupID())
			{
				tempnode->setNext(iteratenode->getNext());
				iteratenode->setNext(tempnode);
				done = true;
			}
		}

		else if (*iteratenode->getData()->getGroupID() > *tempnode->getData()->getGroupID())
		{									// if current major is more than ours
			if (iteratenode == head)
			{
				head = tempnode;
				skipprevious = head;
			}

			else
			{
				previous->setNext(tempnode);
			}

			skipprevious->setSkipNext(tempnode);
			tempnode->setNext(iteratenode);
			tempnode->setSkipNext(iteratenode);
			done = true;
		}

		else if (*iteratenode->getData()->getGroupID() < *tempnode->getData()->getGroupID())
		{									// if current major is less than ours
			if (iteratenode->getNext() == nullptr)
			{									// if our major is the highest in the list
				tempnode->setNext(iteratenode->getNext());
				iteratenode->setNext(tempnode);
				skipprevious->setSkipNext(tempnode);
				done = true;
			}

			else if (*iteratenode->getNext()->getData()->getGroupID() > *tempnode->getData()->getGroupID())
			{									// if next's major is more than ours
				tempnode->setNext(iteratenode->getNext());
				iteratenode->setNext(tempnode);
				tempnode->setSkipNext(skipprevious->getSkipNext());
				skipprevious->setSkipNext(tempnode);
				done = true;
			}
		}

		if (skipprevious->getSkipNext() == iteratenode)
		{
			skipprevious = iteratenode;
		}

		if (!done)
		{
			previous = iteratenode;
			iteratenode = iteratenode->getNext();
		}

		else if (done)
		{
			skipprevious = head;
		}
	}
}

void SLL::deleteStudent(string* deletetarget)
{
	Node* tempnode = new Node();
	Node* previous = new Node();
	tempnode = head;
	previous = head;

	string* student;
	bool done = false;

	while (!done)
	{
		student = new string(*tempnode->getData()->getStudentName());
		if (*student == *deletetarget)
		{
			if (tempnode == head)
			{
				head = head->getNext();
			}
			
			previous->setNext(tempnode->getNext());
			delete tempnode;
			done = true;
		}

		else if (tempnode->getNext() == nullptr)
		{
			done = true;
		}
		previous = tempnode;
		tempnode = tempnode->getNext();
	}
}

void SLL::deleteInOrder(string* deletetarget)
{
	bool done = false;
	Node* tempnode = head;
	Node* previous = tempnode;
	skipprevious = head;

	while (!done)
	{
		string* student = tempnode->getData()->getStudentName();
		if (*student == *deletetarget)
		{						// if current has the student to delete
			if (tempnode == head)
			{						// if current is the head
				head = tempnode->getNext();
				if (head != nullptr)
				{
					head->setSkipNext(tempnode->getSkipNext());
				}
				done = true;
				delete tempnode;
			}

			else if (skipprevious->getSkipNext() == tempnode)
			{						// if current is the first in its range
				skipprevious->setSkipNext(tempnode->getNext());
				previous->setNext(tempnode->getNext());
				done = true;

				if (tempnode->getNext() != tempnode->getSkipNext())
				{
					tempnode->getNext()->setSkipNext(tempnode->getSkipNext());
				}

				delete tempnode;
			}

			else if (tempnode->getNext() == skipprevious->getSkipNext())
			{						// if current is the last in its range
				previous->setNext(tempnode->getNext());
				done = true;
				delete tempnode;
			}

			else
			{
				previous->setNext(tempnode->getNext());
				done = true;
				delete tempnode;
			}

		}

		else if (tempnode->getNext() == nullptr)
		{
			done = true;
		}

		if (!done)
		{
			if (skipprevious->getSkipNext() == tempnode)
			{						//
				skipprevious = tempnode;
				skipprevious->setSkipNext(tempnode->getSkipNext());
			}
			previous = tempnode;
			tempnode = tempnode->getNext();
			
		}

		if (done)
		{
			skipprevious = head;
		}
	}
}

void SLL::print(string* type, int* temp)
{
	Node* printnode = head;
	int count = 0;

	cout << "----------------------------------------------------------" << endl;
	cout << "Classified student information: " << endl;
	cout << "Name\tUsername GPA\tMajor\tGroup ID" << endl;
	while (printnode != nullptr)
	{
		if (*type == "gpa")
		{
			if (*printnode->getData()->getGPARange() == *temp)
			{
				printnode->getData()->print();
				count++;
			}
		}

		if (*type == "major")
		{
			if (*printnode->getData()->getMajor() == *temp)
			{
				printnode->getData()->print();
				count++;
			}
		}

		if (*type == "group")
		{
			if (*printnode->getData()->getGroupID() == *temp)
			{
				printnode->getData()->print();
				count++;
			}
		}

		printnode = printnode->getNext();
	}

	if (count == 0)
	{
		cout << "No records were found" << endl;
	}
}