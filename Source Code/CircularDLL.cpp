#include "CircularDLL.h"
CircularDLL::CircularDLL() {
	this->tail = NULL;
}
CircularDLL::~CircularDLL() {

}
void CircularDLL::TypesOfCircularDLL() {
	cout << "*****Circular (Doubly Linked List)*****" << endl;
	this->Traverse();
	cout << "After Creating a Node(s)" << endl;
	this->CreateNode(10);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Inserting a Node(s) Front" << endl;
	this->InsertFront(20);
	this->InsertFront(30);
	this->InsertFront(40);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Inserting a Node(s) Back" << endl;
	this->InsertBack(50);
	this->InsertBack(60);
	this->InsertBack(70);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "Printing data in reverse" << endl;
	this->ReverseTraverse();
	this->Traverse();
	cout << "After Inserting a Node(s) After" << endl;
	this->InsertAfter(this->tail, 80);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Inserting a Node(s) Before" << endl;
	this->InsertBefore(this->tail->next->next, 90);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting a Node(s) Front" << endl;
	this->DeleteFront();
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting a Node(s) Back" << endl;
	this->DeleteBack();
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting a Node(s) After" << endl;
	this->DeleteAfter(this->tail);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting a Node(s) Before" << endl;
	this->DeleteBefore(this->tail->next);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	this->SearchElement(50);
	cout << "Printing data in reverse" << endl;
	this->ReverseTraverse();
	this->Traverse();
	cout << "After Deleting All Nodes" << endl;
	this->DeleteAllElement();
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	
}
void CircularDLL::Traverse() {
	if (this->tail == NULL) {
		cout << "Circular DoublyLinkedList is empty (Traverse)" << endl;
	}
	else {
		CDNode* currentNode = new CDNode;
		currentNode = this->tail->next;
		do
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		} while (currentNode != this->tail->next);
		cout << endl;
	}
}
void CircularDLL::DeleteAllElement() {
	if (this->tail == NULL) {
		cout << "Circular DoublyLinkedList is empty!!! (Delete All Element)" << endl;
		return;
	}
	CDNode* currentNode = new CDNode;
	currentNode = this->tail->next;
	do
	{
		currentNode = currentNode->next;
		delete this->tail->next;
		this->tail->next = currentNode;
	} while (currentNode != this->tail);
	this->tail = NULL;
	delete this->tail;
	cout << "All elements have been deleted (Delete All Element)" << endl;
}
void CircularDLL::ReverseTraverse() {
	if (this->tail == NULL) {
		cout << "Circular DoublyLinkedList is empty!!! (Reverse Traverse)" << endl;
		return;
	}
	CDNode* nextNode = new CDNode;
	CDNode* currentNode = new CDNode;
	currentNode = tail->next;
	nextNode = currentNode->next;
	currentNode->prev = nextNode;
	currentNode->next = this->tail;
	do
	{
		nextNode->prev = nextNode->next;
		nextNode->next = currentNode;
		currentNode = nextNode;
		nextNode = nextNode->prev;
	} while (nextNode != this->tail);
	nextNode->prev = nextNode->next;
	nextNode->next = currentNode;
	this->tail = this->tail->prev;
}
void CircularDLL::SearchElement(int n) {
	int index = 1;
	if (this->tail == NULL) {
		cout << "Circular DoublyLinkedList is empty!!! (Search Element)" << endl;
	}
	else {
		CDNode* currentNode = new CDNode;
		currentNode = this->tail->next;
		do
		{
			if (currentNode->data == n) {
				cout << "Element " << n << " found at index " << index << " (Search Element)" << endl;
				return;
			}
			index++;
			currentNode = currentNode->next;
		} while (currentNode != this->tail->next);
		cout << "No element found (Search Element)" << endl;
	}
}
int CircularDLL::CountNodes() {
	int count = 0;
	if (this->tail == NULL) {
		cout << "Circular DoublyLinkedList is empty!!! (CountNodes)" << endl;
		return count;
	}
	else {
		CDNode* currentNode = new CDNode;
		currentNode = this->tail->next;
		do
		{
			count++;
			currentNode = currentNode->next;
		} while (currentNode != tail->next);
		return count;
	}
}
void CircularDLL::DeleteBefore(CDNode* nextNode) {
	if (nextNode->next == NULL) {
		cout << "Circular DoublyLinkedList is empty (DeleteBefore)" << endl;
		return;
	}
	if (this->tail->next == tail) {
		cout << "No previous node to Delete (DeleteBefore)" << endl;
		return;
	}
	CDNode* delNode = new CDNode;
	delNode = nextNode->prev;
	nextNode->prev = delNode->prev;
	nextNode->prev->next = nextNode;
	if (nextNode == this->tail->next) {
		this->tail = nextNode->prev;
	}
	delete delNode;
}
void CircularDLL::DeleteAfter(CDNode* prevNode) {
	if (this->tail == NULL) {
		cout << "Circular DoublyLinkedList is empty (DeleteAfter)" << endl;
	}
	else if (this->tail->next == this->tail) {
		cout << "No next node to Delete (DeleteAfter)" << endl;
	}
	else {
		CDNode* delNode = new CDNode;
		delNode = prevNode->next;
		delNode->next->prev = prevNode;
		prevNode->next = delNode->next;
		if (delNode == this->tail) {
			this->tail = prevNode;
		}
		delete delNode;
	}
}
void CircularDLL::DeleteBack() {
	if (this->tail == NULL) {
		cout << "Circular DoublyLinkedList is empty (DeleteFront)" << endl;
		return;
	}
	if (this->tail->next == this->tail) {
		delete this->tail;
		this->tail = NULL;
		return;
	}
	CDNode* delNode = new CDNode;
	delNode = this->tail;
	this->tail->next->prev = this->tail->prev;
	this->tail->prev->next = this->tail->next;
	this->tail = this->tail->prev;
	delete delNode;
}
void CircularDLL::DeleteFront() {
	if (this->tail == NULL) {
		cout << "Circular DoublyLinkedList is empty (DeleteFront)" << endl;
		return;
	}
	if (this->tail->next == this->tail) {
		delete this->tail;
		this->tail = NULL;
		return;
	}
	CDNode* delNode = new CDNode;
	delNode = this->tail->next;
	delNode->prev = this->tail;
	this->tail->next = delNode->next;
	delete delNode;
}
void CircularDLL::InsertBefore(CDNode* nextNode, int n) {
	if (nextNode == NULL) {
		cout << "No Next Node cannot be null (InsertAfter)" << endl;
		return;
	}
	CDNode* newNode = new CDNode;
	newNode->data = n;
	newNode->prev = nextNode->prev;
	newNode->next = nextNode;
	nextNode->prev = newNode;
	newNode->prev->next = newNode;
}
void CircularDLL::InsertAfter(CDNode* prevNode, int n) {
	if (prevNode == NULL) {
		cout << "No Previous Node cannot be null (InsertAfter)" << endl;
		return;
	}
	CDNode* newNode = new CDNode;
	newNode->data = n;
	CDNode* nextNode = prevNode->next;
	prevNode->next = newNode;
	newNode->prev = prevNode;
	newNode->next = nextNode;
	nextNode->prev = newNode;
	if (prevNode == this->tail) {
		this->tail = this->tail->next;
	}
}
void CircularDLL::InsertBack(int n) {
	CDNode* newNode = new CDNode;
	newNode->data = n;
	if (this->tail == NULL) {
		newNode->prev = newNode;
		newNode->next = newNode;
		this->tail = newNode;
		return;
	}
	newNode->next = this->tail->next;
	newNode->prev = this->tail;
	this->tail->next = newNode;
	this->tail = this->tail->next;
}
void CircularDLL::InsertFront(int n) {
	CDNode* newNode = new CDNode;
	newNode->data = n;
	if (this->tail == NULL) {
		newNode->prev = newNode;
		newNode->next = newNode;
		this->tail = newNode;
		return;
	}
	newNode->next = this->tail->next;
	newNode->prev = this->tail;
	this->tail->next->prev = newNode;
	this->tail->next = newNode;
}
void CircularDLL::CreateNode(int n) {
	CDNode* newNode = new CDNode;
	newNode->prev = newNode;
	newNode->data = n;
	newNode->next = newNode;
	this->tail = newNode;
}