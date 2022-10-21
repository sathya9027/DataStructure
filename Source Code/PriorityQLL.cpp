#include "PriorityQLL.h"
PriorityQLL::PriorityQLL() {
	this->rear = NULL;
	this->front = NULL;
}
PriorityQLL::~PriorityQLL() {

}
void PriorityQLL::TypeOfPriorityQLL() {
	cout << "*****Priority Queue Linked List*****" << endl;
	this->Traverse(); 
	cout << "After EnQueue Operation" << endl;
	this->EnQueue(3, 10);
	this->EnQueue(1, 20);
	this->EnQueue(2, 30);
	this->EnQueue(4, 50);
	this->Traverse();
	cout << "After DeQueue Operation" << endl;
	this->DeQueue();
	this->Traverse();
	cout << "After Checking Front Element" << endl;
	this->FrontElement();
	cout << "After Checking Rear Element" << endl;
	this->RearElement();
	cout << "After Checking Queue Is Empty" << endl;
	if (this->IsEmpty()) {
		cout << "Queue is Empty (Type Of Priority QLL)" << endl;
	}
	else {
		cout << "Queue is not Empty (Type Of Priority QLL)" << endl;
	}
	cout << "After Checking Size Of The Priority Queue" << endl;
	this->Traverse();
	this->GetSize();
}
void PriorityQLL::EnQueue(int prior, int n) {
	PQLL* newNode = new PQLL;
	newNode->data = n;
	newNode->priority = prior;
	if (this->front == NULL) {
		newNode->next = this->front;
		this->front = newNode;
		this->rear = newNode;
	}
	else if (prior < this->front->priority) {
		newNode->next = this->front;
		this->front = newNode;
	}
	else {
		PQLL* currentNode = new PQLL;
		currentNode = this->front;
		while (currentNode->next != NULL && currentNode->next->priority <= prior)
		{
			currentNode = currentNode->next;
		}
		newNode->next = currentNode->next;
		currentNode->next = newNode;
		while (this->rear->next != NULL)
		{
			this->rear = this->rear->next;
		}
	}
}
void PriorityQLL::DeQueue() {
	if (this->IsEmpty()) {
		cout << "Priority Queue Linked List is Empty (DeQueue)" << endl;
		return;
	}
	PQLL* delNode = new PQLL;
	PQLL* prevNode = new PQLL;
	delNode = this->front;
	prevNode = this->front;
	while (delNode != this->rear)
	{
		prevNode = delNode;
		delNode = delNode->next;
	}
	prevNode->next = NULL;
	this->rear = prevNode;
	//cout << delNode->data << " is deleted" << endl;
	delete delNode;
}
void PriorityQLL::FrontElement() {
	if (this->IsEmpty()) {
		cout << "Priority Queue Linked List is Empty (FrontElement)" << endl;
		return;
	}
	cout << "Front element: " << this->front->data << endl;
}
void PriorityQLL::RearElement() {
	if (this->IsEmpty()) {
		cout << "Priority Queue Linked List is Empty (RearElement)" << endl;
		return;
	}
	cout << "Rear element: " << this->rear->data << endl;
}
void PriorityQLL::GetSize() {
	int size = 0;
	if (this->IsEmpty()) {
		cout << "Priority Queue Linked List is Empty (GetSize)" << endl;
		return;
	}
	PQLL* currentNode = new PQLL;
	currentNode = this->front;
	while (currentNode != NULL)
	{
		size++;
		currentNode = currentNode->next;
	}
	cout << "Size of the Queue: " << size << endl;
}
bool PriorityQLL::IsEmpty() {
	return this->front == NULL && this->rear == NULL;
}
void PriorityQLL::Traverse() {
	if (this->IsEmpty()) {
		cout << "PriorityQLL Queue Linked List is Empty (Traverse)" << endl;
		return;
	}
	PQLL* currentNode = new PQLL;
	currentNode = this->front;
	cout << "Priority" << setw(7) << "Data" << endl;
	while (currentNode != NULL)
	{
		cout << setw(4) << currentNode->priority << setw(10) << currentNode->data << endl;
		currentNode = currentNode->next;
	}
}
