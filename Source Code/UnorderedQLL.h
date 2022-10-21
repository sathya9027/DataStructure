#pragma once
#include <iostream>
using namespace std;
struct UPQLLNode
{
	int data;
	UPQLLNode* next;
};
class UnorderedQLL
{
private:
	UPQLLNode* front;
	UPQLLNode* rear;
	void EnQueue(int n);
	void DeQueue();
	void FrontElement();
	void RearElement();
	void GetSize();
	bool IsEmpty();
	void Traverse();
public:
	UnorderedQLL();
	~UnorderedQLL();
	void TypesOfUnorderedQueue();
};

