#pragma once
#include <iostream>
using namespace std;
struct DDLL
{
	int data;
	DDLL* next;
	DDLL* prev;
};
class DequeDLL
{
private:
	DDLL* front;
	DDLL* rear;
	void InsertFront(int n);
	void InsertRear(int n);
	void DeleteFront();
	void DeleteRear();
	void DeleteAllElements();
	void FrontElement();
	void RearElement();
	void GetSize();
	bool IsEmpty();
	void Traverse();
public:
	DequeDLL();
	~DequeDLL();
	void TypeOfDequeDLL();
};

