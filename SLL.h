#ifndef SLL_H_
#define SLL_H_
#include "Node.h"

class SLL
{
public:
	SLL();
	~SLL();
	void add(Student* setStudent);
	void addByGPA(Student* setStudent);
	void addByMajor(Student* setStudent);
	void addByGroupID(Student* setStudent);

	void deleteStudent(string* deletetarget);
	void deleteInOrder(string* deletetarget);

	void print(string* type, int* temp);
private:
	Node* head;
	Node* skipprevious;
	Node* tail;
};
#endif
