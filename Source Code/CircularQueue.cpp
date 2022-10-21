#include "CircularQueue.h"
CircularQueue::CircularQueue() {
	this->front = -1;
	this->rear = -1;
	this->capacity = MAX;
	this->size = 0;
}
CircularQueue::~CircularQueue() {

}
void CircularQueue::TypesOfCircularQueue() {
	cout << "*****Circular Queue*****" << endl;
	this->Traverse();
	cout << "After EnQueue Operation" << endl;
	this->EnQueue(10);
	this->EnQueue(20);
	this->EnQueue(30);
	this->EnQueue(40);
	this->EnQueue(50);
	this->EnQueue(60);
	this->Traverse();
	cout << "After DeQueue Operation" << endl;
	this->DeQueue();
	this->Traverse();
	cout << "After EnQueue Operation" << endl;
	this->EnQueue(60);
	this->Traverse();
	cout << "After DeQueue Operation" << endl;
	this->DeQueue();
	this->DeQueue();
	this->DeQueue();
	this->Traverse();
	cout << "After EnQueue Operation" << endl;
	this->EnQueue(70);
	this->EnQueue(80);
	this->Traverse(); 
	cout << "After Checking Front Element" << endl;
	this->FrontElement();
	cout << "After Checking Rear Element" << endl;
	this->RearElement();
	cout << "After Checking Size Of The Queue" << endl;
	this->Traverse();
	this->GetSize();
}
void CircularQueue::Traverse() {
	if (this->IsEmpty()) {
		cout << "Circular Queue Is Empty (Traverse)" << endl;
		return;
	}
	int i;
	for (i = this->front; i != this->rear; i = (i + 1) % this->capacity)
	{
		cout << this->arr[i] << " ";
	}
	cout << this->arr[i] << endl;
}
void CircularQueue::EnQueue(int n) {
	if (this->IsFull()) {
		cout << "Queue is Full (EnQueue)" << endl;
		return;
	}
	if (this->front == -1) {
		this->front = 0;
	}
	this->rear = (this->rear + 1) % this->capacity;
	this->arr[rear] = n;
	this->size++;
	//cout << n << " is inserted" << endl;
}
void CircularQueue::DeQueue() {
	if (this->IsEmpty()) {
		cout << "Cicular Queue is Empty (DeQueue)" << endl;
		return;
	}
	int temp;
	temp = this->arr[front];
	if (this->front == this->rear) {
		this->front = -1;
		this->rear = -1;
	}
	else {
		this->front = (this->front + 1) % this->capacity;
	}
	this->size--;
	cout << temp << " is deleted" << endl;
}
void CircularQueue::FrontElement() {
	if (this->IsEmpty()) {
		cout << "Circular Queue is Empty (Front Element)" << endl;
		return;
	}
	cout << "Front Element of Queue: " << this->arr[front] << endl;
}
void CircularQueue::RearElement() {
	if (this->IsEmpty()) {
		cout << "Circular Queue is Empty (Rear Element)" << endl;
		return;
	}
	cout << "Rear Element of Queue: " << this->arr[rear] << endl;
}
void CircularQueue::GetSize() {
	if (this->IsEmpty()) {
		cout << "Circular Queue is Empty (Get Size)" << endl;
		return;
	}
	cout << "Size of the Queue: " << this->size << endl;
}
bool CircularQueue::IsEmpty() {
	if (this->front == -1 && this->rear == -1) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularQueue::IsFull() {
	if ((this->rear + 1) % this->capacity == this->front) {
		return true;
	}
	else {
		return false;
	}
}
