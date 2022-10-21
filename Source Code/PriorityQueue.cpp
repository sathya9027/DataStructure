#include "PriorityQueue.h"
PriorityQueue::PriorityQueue() {
	this->front = -1;
	this->rear = -1;
	this->capacity = MAX;
}
PriorityQueue::~PriorityQueue() {

}
bool PriorityQueue::IsEmpty() {
	if (this->front == -1 && this->rear == -1) {
		return true;
	}
	else {
		return false;
	}
}
bool PriorityQueue::IsFull() {
	if (this->rear == (this->capacity - 1)) {
		return true;
	}
	else {
		return false;
	}
}
void PriorityQueue::DeQueueInAscending() {
	if (this->IsEmpty()) {
		cout << "Priority Queue is Empty (DeQueueInAscending)" << endl;
		return;
	}
	int temp;
	temp = this->arr[this->rear];
	if (this->front == this->rear) {
		this->front = -1;
		this->rear = -1;
	}
	else {
		this->rear--;
	}
	cout << temp << " is deleted" << endl;
}
void PriorityQueue::DeQueueInDescending() {
	if (this->IsEmpty()) {
		cout << "Priority Queue is Empty (DeQueueInDescending)" << endl;
		return;
	}
	int temp;
	temp = this->arr[this->front];
	if (this->front == this->rear) {
		this->front = -1;
		this->rear = -1;
	}
	else {
		this->front++;
	}
	cout << temp << " is deleted" << endl;
}
void PriorityQueue::EnQueueInAscending(int n) {
	if (this->IsFull()) {
		cout << "Priority Queue Is Full (EnQueueInAscending)" << endl;
		return;
	}
	int i;
	if (this->front == -1) {
		this->front = 0;
		this->rear = 0;
		this->arr[this->rear] = n;
	}
	else {
		i = this->rear;
		//Ascending Order
		while (n < this->arr[i])
		{
			this->arr[i + 1] = this->arr[i];
			i--;
		}
		i++;
		this->arr[i] = n;
		this->rear++;
	}
	cout << n << " is inserted" << endl;
}
void PriorityQueue::EnQueueInDescending(int n) {
	if (this->IsFull()) {
		cout << "Priority Queue Is Full (EnQueueInDescending)" << endl;
		return;
	}
	int i;
	if (this->front == -1) {
		this->front = 0;
		this->rear = 0;
		this->arr[this->rear] = n;
	}
	else {
		i = this->rear;
		//Descending Order
		while (n > this->arr[i])
		{
			this->arr[i + 1] = this->arr[i];
			i--;
			if (i + 1 == this->front) {
				break;
			}
		}
		i++;
		this->arr[i] = n;
		this->rear++;
	}
	cout << n << " is inserted" << endl;
}
void PriorityQueue::FrontElement() {
	if (this->IsEmpty()) {
		cout << "Priority Queue is Empty (Front Element)" << endl;
		return;
	}
	cout << "Front Element of Queue: " << this->arr[front] << endl;
}
void PriorityQueue::RearElement() {
	if (this->IsEmpty()) {
		cout << "Priority Queue is Empty (Rear Element)" << endl;
		return;
	}
	cout << "Rear Element of Queue: " << this->arr[rear] << endl;
}
void PriorityQueue::Traverse() {
	if (this->IsEmpty()) {
		cout << "Priority Queue Is Empty (Traverse)" << endl;
		return;
	}
	for (int i = this->front; i <= this->rear; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void PriorityQueue::GetSize() {
	if (this->IsEmpty()) {
		cout << "Priority Queue is Empty (Get Size)" << endl;
		return;
	}
	cout << "Size of the Queue: " << this->rear + 1 << endl;
}
void PriorityQueue::PriorityInOrder() {
	cout << "***Priority Queue In Order***" << endl;
	cout << "After EnQueue Operation in Ascending" << endl;
	this->EnQueueInAscending(30);
	this->EnQueueInAscending(40);
	this->EnQueueInAscending(10);
	this->EnQueueInAscending(20);
	this->EnQueueInAscending(60);
	this->EnQueueInAscending(50);
	/*cout << "After EnQueue Operation in Descending" << endl;
	this->EnQueueInDescending(30);
	this->EnQueueInDescending(40);
	this->EnQueueInDescending(10);
	this->EnQueueInDescending(20);
	this->EnQueueInDescending(60);
	this->EnQueueInDescending(50);*/
	this->Traverse();
	cout << "After DeQueue Operation in Ascending" << endl;
	this->DeQueueInAscending();
	/*cout << "After DeQueue Operation in Descending" << endl;
	this->DeQueueInDescending();
	this->DeQueueInDescending();
	this->DeQueueInDescending();
	this->DeQueueInDescending();
	this->DeQueueInDescending();*/
	this->Traverse();
	this->EnQueueInAscending(90);
	this->Traverse();
	cout << "After Checking Front Element" << endl;
	this->FrontElement();
	cout << "After Checking Rear Element" << endl;
	this->RearElement();
	cout << "After Checking Size Of The Queue" << endl;
	this->Traverse();
	this->GetSize();
}
void PriorityQueue::PriorityInSTL() {
	cout << "*****Priority Queue in STL*****" << endl;
	cout << "After Push Operation" << endl;
	this->priority_queue1.push(10);
	this->priority_queue1.push(30);
	this->priority_queue1.push(50);
	this->priority_queue1.push(40);
	this->priority_queue1.push(20);
	this->Display(this->priority_queue1);
	cout << "After Pop Operation" << endl;
	this->priority_queue1.pop();
	this->Display(this->priority_queue1);
	cout << "After Checking Front Element" << endl;
	cout << "Front Element: " << this->priority_queue1.top() << endl;/*
	cout << "After Checking Rear Element" << endl;
	cout << "Rear Element: " << this->priority_queue1.back() << endl;*/
	cout << "After Checking Size of the Queue" << endl;
	cout << "Size of the Queue: " << this->priority_queue1.size() << endl;
	cout << "After Checking Queue is Empty" << endl;
	if (this->priority_queue1.empty()) {
		cout << "Queue is Empty (Types Of Priority Queue In STL)" << endl;
	}
	else {
		cout << "Queue is not Empty (Types Of Priority Queue In STL)" << endl;
	}
	this->priority_queue2.push(30);
	cout << "After Swap Operation" << endl;
	this->priority_queue2.swap(this->priority_queue1);
	cout << "Queue 1: ";
	this->Display(this->priority_queue1);
	cout << "Queue 2: ";
	this->Display(this->priority_queue2);
	cout << "After Emplace Operation" << endl;
	this->priority_queue2.emplace(80);
	this->priority_queue2.emplace(60);
	this->priority_queue2.emplace(70);
	this->Display(this->priority_queue2);
}
void PriorityQueue::Display(priority_queue<int> prior_que) {
	while (!prior_que.empty())
	{
		cout << prior_que.top() << " ";
		prior_que.pop();
	}
	cout << endl;
}
void PriorityQueue::TypesOfPriorityQueueInArray() {
	cout << "*****Priority Queue In Array*****" << endl;
	this->PriorityInOrder();
}
