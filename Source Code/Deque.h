#pragma once
#include <iostream>
//Deque (Circular Array)
#define MAX 5
using namespace std;
class Deque
{
private:
	int arr[MAX];
	int front;
	int rear;
	int size;
	int capacity;
	void Traverse();
	void InsertFront(int n);
	void DeleteFront();
	void InsertRear(int n);
	void DeleteRear();
	void FrontElement();
	void RearElement();
	void GetSize();
	bool IsEmpty();
	bool IsFull();
	void InputRestrictedDeque();
	void OutputRestrictedDeque();
public:
	Deque();
	~Deque();
	void TypesOfCircularArray();
	void TypesOfDeque();
};
