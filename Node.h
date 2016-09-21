#ifndef NODE_H_
#define NODE_H_

#include "Student.h"
using namespace std;

class Node
{
public:
	Node();
	~Node();
	Node(Student* data, Node* next);

	Student* getData();
	void setData(Student* data);

	Node* getNext();
	void setNext(Node* next);

	Node* getSkipNext();
	void setSkipNext(Node* skipnext);

private:
	Student* data;
	Node* next;
	Node* skipnext;
};

#endif