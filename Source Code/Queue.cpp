#include "Queue.h"
Queue::Queue() {
	this->front = -1;
	this->rear = -1;
	this->capacity = MAX;
}
Queue::~Queue() {

}
void Queue::Traverse() {
	if (this->IsEmpty()) {
		cout << "Queue Is Empty (Traverse)" << endl;
		return;
	}
	for (int i = this->front; i <= this->rear; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Queue::EnQueue(int n) {
	if (this->front == -1) {
		this->front = 0;
	}
	if (this->IsFull()) {
		cout << "Queue is Full (EnQueue)" << endl;
		return;
	}
	this->rear++;
	this->arr[rear] = n;
	//cout << n << " is inserted" << endl;
}
void Queue::DeQueue() {
	if (this->IsEmpty()) {
		cout << "Queue is Empty (DeQueue)" << endl;
		return;
	}
	int temp;
	temp = this->arr[rear];
	if (this->front == this->rear) {
		this->front = -1;
		this->rear = -1;
	}
	else {
		this->rear--;
	}
	cout << temp << " is deleted" << endl;
}
void Queue::FrontElement() {
	if (this->IsEmpty()) {
		cout << "Queue is Empty (Front Element)" << endl;
		return;
	}
	cout << "Front Element of Queue: " << this->arr[front] << endl;
}
void Queue::RearElement() {
	if (this->IsEmpty()) {
		cout << "Queue is Empty (Rear Element)" << endl;
		return;
	}
	cout << "Rear Element of Queue: " << this->arr[rear] << endl;
}
void Queue::GetSize() {
	if (this->IsEmpty()) {
		cout << "Queue is Empty (Get Size)" << endl;
		return;
	}
	cout << "Size of the Queue: " << this->rear + 1 << endl;
}
bool Queue::IsEmpty() {
	if (this->front == -1 && this->rear == -1) {
		return true;
	}
	else {
		return false;
	}
}
bool Queue::IsFull() {
	if (this->rear == (this->capacity - 1)) {
		return true;
	}
	else {
		return false;
	}
}
void Queue::Display(queue<int> que) {
	while (!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;
}
void Queue::TypesOfQueueInArray() {
	cout << "*****Queue In Array*****" << endl;
	cout << this->rear << endl;
	cout << "After Creation" << endl;
	this->Traverse();
	cout << this->rear << endl;
	cout << "After EnQueue Operation" << endl;
	this->EnQueue(10);
	this->EnQueue(20);
	this->EnQueue(30);
	this->EnQueue(40);
	this->EnQueue(50);
	this->EnQueue(60);
	this->Traverse();
	cout << this->rear << endl;
	cout << "After DeQueue Operation" << endl;
	this->DeQueue();
	this->DeQueue();
	this->DeQueue();
	cout << this->rear << endl;
	cout << "After Checking Front Element" << endl;
	this->FrontElement();
	cout << this->rear << endl;
	cout << "After Checking Rear Element" << endl;
	this->RearElement();
	cout << this->rear << endl;
	cout << "After Checking Queue Is Empty" << endl;
	if (this->IsEmpty()) {
		cout << "Queue is Empty (Queue In Array)" << endl;
	}
	else {
		cout << "Queue is not Empty (Queue In Array)" << endl;
	}
	cout << this->rear << endl;
	cout << "After Checking Queue Is Full" << endl;
	if (this->IsFull()) {
		cout << "Queue is Full (Queue In Array)" << endl;
	}
	else {
		cout << "Queue is not Full (Queue In Array)" << endl;
	}
	cout << this->rear << endl;
	cout << "After Checking Size Of The Queue" << endl;
	this->Traverse();
	this->GetSize();
	cout << this->rear << endl;
}
void Queue::TypesOfQueueInSTL() {
	cout << "*****Queue in STL*****" << endl;
	cout << "After Push Operation" << endl;
	this->queueSTL1.push(10);
	this->queueSTL1.push(20);
	this->queueSTL1.push(30);
	this->queueSTL1.push(40);
	this->queueSTL1.push(50);
	this->Display(this->queueSTL1);
	cout << "After Pop Operation" << endl;
	this->queueSTL1.pop();
	this->Display(this->queueSTL1);
	cout << "After Checking Front Element" << endl;
	cout << "Front Element: " << this->queueSTL1.front() << endl;
	cout << "After Checking Rear Element" << endl;
	cout << "Rear Element: " << this->queueSTL1.back() << endl;
	cout << "After Checking Size of the Queue" << endl;
	cout << "Size of the Queue: " << this->queueSTL1.size() << endl;
	cout << "After Checking Queue is Empty" << endl;
	if (this->queueSTL1.empty()) {
		cout << "Queue is Empty (Types Of Queue In STL)" << endl;
	}
	else {
		cout << "Queue is not Empty (Types Of Queue In STL)" << endl;
	}
	this->queueSTL2.push(30);
	cout << "After Swap Operation" << endl;
	this->queueSTL2.swap(this->queueSTL1);
	cout << "Queue 1: ";
	this->Display(this->queueSTL1);
	cout << "Queue 2: ";
	this->Display(this->queueSTL2);
	cout << "After Emplace Operation" << endl;
	this->queueSTL2.emplace(60);
	this->queueSTL2.emplace(70);
	this->queueSTL2.emplace(80);
	this->Display(this->queueSTL2);
}
