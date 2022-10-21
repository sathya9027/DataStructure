#pragma once
#include <iostream>
#include <queue>
using namespace std;
#define MAX 5
class Queue
{
private:
	int front;
	int rear;
	int arr[MAX];
	int capacity;
	queue<int> queueSTL1;
	queue<int> queueSTL2;
	void Traverse();
	void EnQueue(int n);
	void DeQueue();
	void FrontElement();
	void RearElement();
	void GetSize();
	bool IsEmpty();
	bool IsFull();
	void Display(queue<int> que);
public:
	Queue();
	~Queue();
	void TypesOfQueueInArray();
	void TypesOfQueueInSTL();
};

