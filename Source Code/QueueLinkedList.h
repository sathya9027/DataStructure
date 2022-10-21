#pragma once
#include<iostream>
using namespace std;
struct QLLNode
{
	int data;
	QLLNode* next;
};
class QueueLinkedList
{
private:
	QLLNode* front;
	QLLNode* rear;
	void EnQueue(int n);
	void DeQueue();
	void FrontElement();
	void RearElement();
	void GetSize();
	bool IsEmpty();
	void Traverse();
public:
	QueueLinkedList();
	~QueueLinkedList();
	void TypesOfQueue();
};

