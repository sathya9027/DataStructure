#include "UnorderedQLL.h"
UnorderedQLL::UnorderedQLL() {
	this->rear = NULL;
	this->front = NULL;
}
UnorderedQLL::~UnorderedQLL() {

}

void UnorderedQLL::TypesOfUnorderedQueue() {
	cout << "*****Queue In Linked List*****" << endl;
	/*cout << "After EnQueue Operation" << endl;
	this->EnQueue(10);
	this->EnQueue(20);
	this->EnQueue(30);
	this->EnQueue(40);
	this->EnQueue(50);
	this->Traverse();
	cout << "After DeQueue Operation" << endl;
	this->DeQueue();
	this->DeQueue();
	this->Traverse();*/
	cout << "After Checking Front Element" << endl;
	this->FrontElement();
	cout << "After Checking Rear Element" << endl;
	this->RearElement();
	cout << "After Checking Queue Is Empty" << endl;
	if (this->IsEmpty()) {
		cout << "Queue is Empty (Types Of Unordered Queue)" << endl;
	}
	else {
		cout << "Queue is not Empty (Types Of Unordered Queue)" << endl;
	}
	cout << "After Checking Size Of The Unordered Queue" << endl;
	this->Traverse();
	this->GetSize();
}
void UnorderedQLL::EnQueue(int n) {
	UPQLLNode* newNode = new UPQLLNode;
	newNode->data = n;
	newNode->next = this->rear;
	if (this->IsEmpty()) {
		this->front = newNode;
	}
	this->rear = newNode;
	cout << this->rear->data << " is inserted" << endl;
}
void UnorderedQLL::DeQueue() {
	if (this->IsEmpty()) {
		cout << "Unordered Queue Linked List is Empty (DeQueue)" << endl;
		return;
	}
	UPQLLNode* delNode = new UPQLLNode;
	delNode = this->rear;
	this->rear = this->rear->next;
	cout << delNode->data << " is deleted" << endl;
	delete delNode;
}
void UnorderedQLL::FrontElement() {
	if (this->IsEmpty()) {
		cout << "Unordered Queue Linked List is Empty (FrontElement)" << endl;
		return;
	}
	cout << "Front element: " << this->front->data << endl;
}
void UnorderedQLL::RearElement() {
	if (this->IsEmpty()) {
		cout << "Unordered Queue Linked List is Empty (RearElement)" << endl;
		return;
	}
	cout << "Rear element: " << this->rear->data << endl;
}
void UnorderedQLL::GetSize() {
	int size = 0;
	if (this->IsEmpty()) {
		cout << "Unordered Queue Linked List is Empty (GetSize)" << endl;
		return;
	}
	UPQLLNode* currentNode = new UPQLLNode;
	currentNode = this->rear;
	while (currentNode != NULL)
	{
		size++;
		currentNode = currentNode->next;
	}
	cout << "Size of the Queue: " << size << endl;
}
bool UnorderedQLL::IsEmpty() {
	return this->rear == NULL;
}
void UnorderedQLL::Traverse() {
	if (this->IsEmpty()) {
		cout << "Unordered Queue Linked List is Empty (Traverse)" << endl;
		return;
	}
	UPQLLNode* currentNode = new UPQLLNode;
	currentNode = this->rear;
	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
	cout << endl;
}
