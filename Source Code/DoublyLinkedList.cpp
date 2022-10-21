#include "DoublyLinkedList.h"
DoublyLinkedList::DoublyLinkedList() {
	this->head = NULL;
}
DoublyLinkedList::~DoublyLinkedList() {

}
void DoublyLinkedList::TypesOfDoublyLinkedList() {
	cout << "*****Doubly Linked List*****" << endl;
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
	cout << "After Inserting a Node(s) After" << endl;
	this->InsertAfter(this->head, 80);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Inserting a Node(s) Before" << endl;
	this->InsertBefore(this->head, 90);
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
	this->DeleteAfter(this->head->next->next->next->next->next->next);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting a Node(s) Before" << endl;
	this->DeleteBefore(this->head->next);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "Searching a element" << endl;
	this->SearchElement(20);
	cout << "After Reverse Traverse" << endl;
	this->ReverseTraverse();
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting all Element(s)" << endl;
	this->DeleteAllElement();
	cout << "No of Nodes: " << this->CountNodes() << endl;
}
void DoublyLinkedList::ReverseTraverse() {
	if (this->head == NULL) {
		cout << "DoublyLinkedList is empty!!! (ReverseTraverse)" << endl;
	}
	DNode* currentNode = new DNode;
	currentNode = this->head;
	DNode* nextNode = new DNode;
	nextNode = currentNode->next;
	currentNode->next = NULL;
	currentNode->prev = nextNode;
	while (nextNode != NULL)
	{
		nextNode->prev = nextNode->next;
		nextNode->next = currentNode;
		currentNode = nextNode;
		nextNode = nextNode->prev;
	}
	this->head = currentNode;
}
void DoublyLinkedList::SearchElement(int n) {
	int index = 1;
	if (this->head == NULL) {
		cout << "DoublyLinkedList is empty!!! (Search Element)" << endl;
	}
	else {
		DNode* currentNode = new DNode;
		currentNode = this->head;
		while (currentNode != NULL)
		{
			if (currentNode->data == n) {
				cout << "Element " << n << " found at index " << index << " (Search Element)" << endl;
				return;
			}
			index++;
			currentNode = currentNode->next;
		}
		cout << "No element found (Search Element)" << endl;
	}
}
void DoublyLinkedList::DeleteAllElement() {
	if (this->head == NULL) {
		cout << "DoublyLinkedList is empty!!! (Delete All Element)" << endl;
		return;
	}
	DNode* currentNode = new DNode;
	currentNode = this->head;
	while (currentNode != NULL)
	{
		currentNode = currentNode->next;
		delete this->head;
		this->head = currentNode;
	}
	cout << "All elements have been deleted" << endl;
}
int DoublyLinkedList::CountNodes() {
	int count = 0;
	if (this->head == NULL) {
		cout << "DoublyLinkedList is empty!!! (CountNodes)" << endl;
		return count;
	}
	else {
		DNode* currentNode = new DNode;
		currentNode = this->head;
		while (currentNode != NULL)
		{
			count++;
			currentNode = currentNode->next;
		}
		return count;
	}
}
void DoublyLinkedList::DeleteBefore(DNode* nextNode) {
	if (this->head == NULL) {
		cout << "DoublyLinkedList is empty!!! (DeleteBefore)" << endl;
	}
	else {
		if (nextNode == NULL) {
			cout << "No next Node to Delete (DeleteBefore)" << endl;
			return;
		}
		else if (nextNode->prev == NULL) {
			cout << "No previous Node to Delete (DeleteBefore)" << endl;
			return;
		}
		else {
			DNode* delNode = new DNode;
			delNode = nextNode->prev;
			nextNode->prev = delNode->prev;
			if (delNode != this->head) {
				nextNode->prev->next = nextNode;
			}
			else {
				this->head = nextNode;
			}
			delete delNode;
		}
	}
}
void DoublyLinkedList::DeleteAfter(DNode* prevNode) {
	if (this->head == NULL) {
		cout << "DoublyLinkedList is empty!!! (DeleteAfter)" << endl;
	}
	else {
		if (prevNode->next == NULL) {
			cout << "No next Node to Delete (DeleteAfter)" << endl;
			return;
		}
		else {
			DNode* delNode = new DNode;
			delNode = prevNode->next;
			prevNode->next = delNode->next;
			if (prevNode->next != NULL) {
				prevNode->next->prev = prevNode;
			}
			delete delNode;
		}
	}
}
void DoublyLinkedList::DeleteBack() {
	if (this->head == NULL) {
		cout << "Head node cannot be NULL (DeleteBack)" << endl;
		return;
	}
	else if (this->head->next == NULL) {
		delete this->head;
		this->head = NULL;
	}
	else {
		DNode* delNode = new DNode;
		DNode* prevNode = new DNode;
		delNode = this->head;
		while (delNode->next != NULL)
		{
			delNode = delNode->next;
		}
		prevNode = delNode->prev;
		prevNode->next = NULL;
		delete delNode;
	}
}
void DoublyLinkedList::DeleteFront() {
	if (this->head == NULL) {
		cout << "Head node cannot be NULL (DeleteFront)" << endl;
		return;
	}
	DNode* delNode = new DNode;
	delNode = this->head;
	this->head = this->head->next;
	if (this->head != NULL) {
		head->prev = NULL;
	}
	delete delNode;
}
void DoublyLinkedList::InsertBefore(DNode* nextNode, int n) {
	if (nextNode == NULL) {
		cout << "The given previous node cannot be NULL (InsertBefore)" << endl;
		return;
	}
	DNode* newNode = new DNode;
	newNode->data = n;
	newNode->prev = nextNode->prev;
	nextNode->prev = newNode;
	newNode->next = nextNode;
	if (newNode->prev != NULL) {
		newNode->prev->next = newNode;
		return;
	}
	this->head = newNode;
}
void DoublyLinkedList::InsertAfter(DNode* prevNode, int n) {
	if (prevNode == NULL) {
		cout << "The given previous node cannot be NULL (InsertAfter)" << endl;
		return;
	}
	DNode* newNode = new DNode;
	newNode->data = n;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
	newNode->prev = prevNode;
	if (newNode->next != NULL) {
		newNode->next->prev = newNode;
	}
}
void DoublyLinkedList::InsertBack(int n) {
	DNode* newNode = new DNode;
	newNode->prev = NULL;
	newNode->data = n;
	newNode->next = NULL;
	if (this->head != NULL) {
		DNode* prevNode = new DNode;
		prevNode = this->head;
		while (prevNode->next != NULL)
		{
			prevNode = prevNode->next;
		}
		newNode->prev = prevNode;
		prevNode->next = newNode;
		return;
	}
	this->head = newNode;
}
void DoublyLinkedList::InsertFront(int n) {
	DNode* newNode = new DNode;
	newNode->prev = NULL;
	newNode->data = n;
	newNode->next = NULL;
	if (this->head != NULL) {
		this->head->prev = newNode;
		newNode->next = this->head;
	}
	this->head = newNode;
}
void DoublyLinkedList::CreateNode(int n) {
	DNode* newNode = new DNode;
	newNode->prev = NULL;
	newNode->data = n;
	newNode->next = NULL;
	this->head = newNode;
}
void DoublyLinkedList::Traverse() {
	if (this->head == NULL) {
		cout << "DoublyLinkedList is empty (Traverse)" << endl;
	}
	else {
		DNode* currentNode = new DNode;
		currentNode = this->head;
		while (currentNode != NULL)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << endl;
	}
}