#include "DequeDLL.h"
DequeDLL::DequeDLL() {
	this->front = NULL;
	this->rear = NULL;
}
DequeDLL::~DequeDLL() {

}
void DequeDLL::InsertFront(int n) {
	DDLL* newNode = new DDLL;
	newNode->data = n;
	newNode->prev = NULL;
	newNode->next = NULL;
	if (this->IsEmpty()) {
		this->front = newNode;
		this->rear = newNode;
	}
	else {
		newNode->next = front;
		front->prev = newNode;
		front = newNode;
	}
}
void DequeDLL::InsertRear(int n) {
	DDLL* newNode = new DDLL;
	newNode->data = n;
	newNode->prev = NULL;
	newNode->next = NULL;
	if (this->IsEmpty()) {
		this->front = newNode;
		this->rear = newNode;
	}
	else {
		newNode->prev = rear;
		rear->next = newNode;
		rear = newNode;
	}
}
void DequeDLL::DeleteFront() {
	if (this->IsEmpty()) {
		cout << "Deque DLL is Empty (Delete Front)" << endl;
		return;
	}
	if (front == rear) {
		this->front = NULL;
		this->rear = NULL;
	}
	else {
		DDLL* delNode = new DDLL;
		delNode = front;
		front = front->next;
		front->prev = NULL;
		delete delNode;
	}
}
void DequeDLL::DeleteRear() {
	if (this->IsEmpty()) {
		cout << "Deque DLL is Empty (Delete Rear)" << endl;
		return;
	}
	if (front == rear) {
		this->front = NULL;
		this->rear = NULL;
	}
	else {
		DDLL* delNode = new DDLL;
		delNode = rear;
		rear = rear->prev;
		rear->next = NULL;
		delete delNode;
	}
}
void DequeDLL::DeleteAllElements() {
	if (this->IsEmpty()) {
		cout << "Deque DLL is Empty (Delete All Elements)" << endl;
		return;
	}

	DDLL* currentNode = new DDLL;
	currentNode = this->front;
	while (currentNode != NULL)
	{
		currentNode = currentNode->next;
		delete this->front;
		this->front = currentNode;
		this->rear = currentNode;
	}
	cout << "All elements have been deleted" << endl;
}
void DequeDLL::FrontElement() {
	if (this->IsEmpty()) {
		cout << "Deque DLL is Empty (Front Element)" << endl;
		return;
	}
	cout << "Front Element: " << this->front->data << endl;
}
void DequeDLL::RearElement() {
	if (this->IsEmpty()) {
		cout << "Deque DLL is Empty (Rear Element)" << endl;
		return;
	}
	cout << "Rear Element: " << this->rear->data << endl;
}
void DequeDLL::GetSize() {
	if (this->IsEmpty()) {
		cout << "Deque DLL is Empty (Get Size)" << endl;
		return;
	}
	int size = 0; 
	DDLL* currentNode = new DDLL;
	currentNode = this->front;
	while (currentNode != NULL)
	{
		size++;
		currentNode = currentNode->next;
	}
	cout << "Size: " << size << endl;
}
bool DequeDLL::IsEmpty() {
	return front == NULL && rear == NULL;
}
void DequeDLL::Traverse() {
	if (this->IsEmpty()) {
		cout << "Deque DLL is Empty (Traverse)" << endl;
		return;
	}
	DDLL* currentNode = new DDLL;
	currentNode = this->front;
	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
	cout << endl;
}
void DequeDLL::TypeOfDequeDLL() {
	cout << "*****Deque In Doubly Linked List*****" << endl;
	cout << "After Creation" << endl;
	this->Traverse();
	cout << "After Insertion (Front)" << endl;
	this->InsertFront(10);
	this->InsertFront(20);
	this->InsertFront(30);
	this->Traverse();
	cout << "After Insertion (Rear)" << endl;
	this->InsertRear(40);
	this->InsertRear(50);
	this->InsertRear(60);
	this->Traverse();
	cout << "After Deletion (Front)" << endl;
	this->DeleteFront();
	this->Traverse();
	cout << "After Deletion (Rear)" << endl;
	this->DeleteRear();
	this->Traverse();
	cout << "After Checking Front Element" << endl;
	this->Traverse();
	this->FrontElement();
	cout << "After Checking Rear Element" << endl;
	this->Traverse();
	this->RearElement();
	cout << "After Checking Size of the List" << endl;
	this->Traverse();
	this->GetSize();
	if (this->IsEmpty()) {
		cout << "Deque Doubly Linked List is Empty (Type Of Deque DLL)" << endl;
	}
	else {
		cout << "Deque Doubly Linked List is not Empty (Type Of Deque DLL)" << endl;
	}
	cout << "After Deleting All Elements" << endl;
	this->DeleteAllElements();
	this->Traverse();
}
