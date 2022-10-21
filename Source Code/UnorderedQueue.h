#pragma once
#include <iostream>
#include <queue>
using namespace std;
#define MAX 5
class UnorderedQueue
{
private:
	int front;
	int rear;
	int capacity;
	int arr[MAX];
	void EnQueue(int n);
	void DeQueue();
	bool IsEmpty();
	bool IsFull();
	void FrontElement();
	void RearElement();
	void Traverse();
	void GetSize();
public:
	UnorderedQueue();
	~UnorderedQueue();
	void PriorityInUnorder();
};

