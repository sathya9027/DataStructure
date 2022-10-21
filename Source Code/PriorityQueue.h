#pragma once
#include <queue>
#include <iostream>
using namespace std;
#define MAX 5
class PriorityQueue
{
private:
	priority_queue<int> priority_queue1;
	priority_queue<int> priority_queue2;
	int front;
	int rear;
	int capacity;
	int arr[MAX];
	bool IsEmpty();
	bool IsFull();
	void DeQueueInAscending();
	void DeQueueInDescending();
	void EnQueueInAscending(int n);
	void EnQueueInDescending(int n);
	void FrontElement();
	void RearElement();
	void Traverse();
	void GetSize();
	void PriorityInOrder();
	void Display(priority_queue<int> prior_que);
public:
	PriorityQueue();
	~PriorityQueue();
	void PriorityInSTL();
	void TypesOfPriorityQueueInArray();
};

