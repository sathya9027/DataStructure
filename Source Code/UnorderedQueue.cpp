#include "UnorderedQueue.h"
UnorderedQueue::UnorderedQueue() {
	this->front = -1;
	this->rear = -1;
	this->capacity = MAX;
}
UnorderedQueue::~UnorderedQueue() {

}
void UnorderedQueue::EnQueue(int n) {
	if (this->front == -1) {
		this->front = 0;
	}
	if (this->IsFull()) {
		cout << "Unordered Priority Queue is Full (EnQueue)" << endl;
		return;
	}
	this->rear++;
	this->arr[this->rear] = n;
	//cout << n << " is inserted" << endl;s
}
void UnorderedQueue::DeQueue() {
	if (this->IsEmpty()) {
		cout << "Unordered Priority Queue is Empty (DeQueue)" << endl;
		return;
	}
	int temp;
	int max = 0;
	//max element
	for (int i = 1; i <= this->rear; i++)
	{
		if (this->arr[max] < this->arr[i]) {
			max = i;
		}
	}
	temp = this->arr[max];
	//deleting the max element
	for (int i = max; i <= this->rear; i++)
	{
		this->arr[i] = this->arr[i + 1];
	}
	if (this->front == this->rear) {
		this->front = -1;
		this->rear = -1;
	}
	else {
		this->rear--;
	}
	//cout << temp << " is deleted" << endl;
}
bool UnorderedQueue::IsEmpty() {
	if (this->front == -1 && this->rear == -1) {
		return true;
	}
	else {
		return false;
	}
}
bool UnorderedQueue::IsFull() {
	if (this->rear == (this->capacity - 1)) {
		return true;
	}
	else {
		return false;
	}
}
void UnorderedQueue::FrontElement() {
	if (this->IsEmpty()) {
		cout << "Unordered Priority Queue is Empty (Front Element)" << endl;
		return;
	}
	cout << "Front Element of Queue: " << this->arr[front] << endl;
}
void UnorderedQueue::RearElement() {
	if (this->IsEmpty()) {
		cout << "Unordered Priority Queue is Empty (Rear Element)" << endl;
		return;
	}
	cout << "Rear Element of Queue: " << this->arr[rear] << endl;
}
void UnorderedQueue::Traverse() {
	if (this->IsEmpty()) {
		cout << "Unordered Priority Queue Is Empty (Traverse)" << endl;
		return;
	}
	for (int i = this->front; i <= this->rear; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void UnorderedQueue::GetSize() {
	if (this->IsEmpty()) {
		cout << "Unordered Priority Queue is Empty (Get Size)" << endl;
		return;
	}
	cout << "Size of the Queue: " << this->rear + 1 << endl;
}
void UnorderedQueue::PriorityInUnorder() {
	cout << "***Unordered Priority Queue***" << endl;
	cout << "After EnQueue Operation" << endl;
	this->EnQueue(10);
	this->EnQueue(40);
	this->EnQueue(20);
	this->EnQueue(50);
	this->EnQueue(30);
	this->EnQueue(60); 
	this->Traverse();
	cout << "After DeQueue Operation" << endl;
	this->DeQueue();
	this->DeQueue();
	this->Traverse();
	cout << "After Checking Front Element" << endl;
	this->FrontElement();
	cout << "After Checking Rear Element" << endl;
	this->RearElement();
	cout << "After Checking Size Of The Queue" << endl;
	this->Traverse();
	this->GetSize();
}
