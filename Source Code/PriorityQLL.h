#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
struct PQLL
{
	int data;
	int priority;
	PQLL* next;
};
class PriorityQLL
{
private:
	PQLL* front;
	PQLL* rear;
	void EnQueue(int prior, int n);
	void DeQueue();
	void FrontElement();
	void RearElement();
	void GetSize();
	bool IsEmpty();
	void Traverse();
public:
	PriorityQLL();
	~PriorityQLL();
	void TypeOfPriorityQLL();
};

