#include "Node.h"

Node::Node()
{
	data = nullptr;
	next = nullptr;
	skipnext = nullptr;
}

Node::~Node()
{
}

Node::Node(Student* data, Node* next)
{
	this->data = data;
	this->next = next;
	skipnext = nullptr;
}

Student* Node::getData()
{
	return data;
}

void Node::setData(Student* data)
{
	this->data = data;
}

Node* Node::getNext()
{
	return next;
}

void Node::setNext(Node* next)
{
	this->next = next;
}

Node* Node::getSkipNext()
{
	return skipnext;
}

void Node::setSkipNext(Node* skipnext)
{
	this->skipnext = skipnext;
}
