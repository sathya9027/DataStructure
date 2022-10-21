#pragma once
#include<iostream>
using namespace std;
struct SLLNode
{
	int data;
	SLLNode* next;
};
class StackLinkedList
{
private:
	SLLNode* top;
	void Push(int n);
	void Pop();
	void Peek();
	void GetSize();
	bool IsEmpty();
	void Traverse();
public:
	StackLinkedList();
	~StackLinkedList();
	void TypesOfStack();
};

