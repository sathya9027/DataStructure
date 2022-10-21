#pragma once
#include<iostream>
using namespace std;
#define MAX 5
class CircularQueue
{
private:
	int arr[MAX];
	int front;
	int rear;
	int capacity;
	int size;
	void Traverse();
	void EnQueue(int n);
	void DeQueue();
	void FrontElement();
	void RearElement();
	void GetSize();
	bool IsEmpty();
	bool IsFull();
public:
	CircularQueue();
	~CircularQueue();
	void TypesOfCircularQueue();
};

