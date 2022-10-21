#include "SinglyLinkedList.h"
SinglyLinkedList::SinglyLinkedList() {
	this->head = NULL;
}
SinglyLinkedList::~SinglyLinkedList() {

}
void SinglyLinkedList::TypesOfSinglyLinkedList() {
	cout << "*****Singly Linked List*****" << endl;
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Creating Node" << endl;
	this->CreateNode(10);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Inserting Node(s)" << endl;
	this->InsertFront(40);
	this->InsertFront(50);
	this->InsertFront(80);
	this->Traverse();
	this->InsertBack(20);
	this->InsertBack(30);
	this->Traverse();
	this->InsertAfter(head->next->next, 60);
	this->Traverse();
	cout << "After Inserting At Position" << endl;
	this->InsertAtPos(7, 70, this->CountNodes());
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting Front" << endl;
	this->DeleteFront();
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting Back" << endl;
	this->DeleteBack();
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting Back Single Pointer" << endl;
	this->DeleteBackSinglePointer();
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting After" << endl;
	this->DeleteAfter(this->head->next);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting At Position" << endl;
	this->DeleteAtPos(2, this->CountNodes());
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "Searching a element" << endl;
	this->SearchElement(20);
	cout << "Printing data in reverse" << endl;
	this->ReverseTraverse();
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting All Elements" << endl;
	this->DeleteAllElement();
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
}
void SinglyLinkedList::DeleteFront() {
	if (this->head == NULL) {
		cout << "No node(s) left to delete (DeleteFront)" << endl;
		return;
	}
	SNode* delNode = new SNode;
	delNode = this->head;
	this->head = this->head->next;
	delete delNode;
}
void SinglyLinkedList::DeleteBack() {
	if (this->head == NULL) {
		cout << "No node(s) left to delete (DeleteBack)" << endl;
		return;
	}
	else if (this->head->next == NULL) {
		delete this->head;
		this->head = NULL;
	}
	else {
		SNode* delNode = new SNode;
		SNode* prevNode = new SNode;
		delNode = this->head;
		prevNode = this->head;
		while (delNode->next != NULL)
		{
			prevNode = delNode;
			delNode = delNode->next;
		}
		prevNode->next = NULL;
		delete delNode;
	}
}
void SinglyLinkedList::DeleteBackSinglePointer() {
	if (this->head == NULL) {
		cout << "No node(s) left to delete (DeleteBackSinglePointer)" << endl;
		return;
	}
	else if (this->head->next == NULL) {
		delete this->head;
		this->head = NULL;
	}
	else {
		SNode* prevNode = new SNode;
		prevNode = this->head;
		while (prevNode->next->next != NULL) {
			prevNode = prevNode->next;
		}
		prevNode->next = NULL;
		delete prevNode->next;
	}
}
void SinglyLinkedList::DeleteAfter(SNode* prevNode) {
	if (this->head == NULL) {
		cout << "SinglyLinkedList is empty!!! (DeleteAfter)" << endl;
	}
	else {
		if (prevNode->next == NULL) {
			cout << "No next Node to Delete (DeleteAfter)" << endl;
			return;
		}
		else {
			SNode* delNode = new SNode;
			delNode = prevNode->next;
			prevNode->next = delNode->next;
			delete delNode;
		}
	}
}
void SinglyLinkedList::DeleteAtPos(int pos, int count) {
	int temp = 1;
	SNode* delNode = new SNode;
	if (pos == 1) {
		delNode = this->head;
		this->head = delNode->next;
		delete delNode;
		return;
	}
	else {
		if (pos == 0 || pos > count) {
			cout << "No node(s) left to delete (DeleteAtPos)" << endl;
			return;
		}
		SNode* prevNode = new SNode;
		prevNode = this->head;
		while (temp < pos - 1)
		{
			prevNode = prevNode->next;
			temp++;
		}
		delNode = prevNode->next;
		prevNode->next = delNode->next;
		delete delNode;
	}
}
void SinglyLinkedList::SearchElement(int n) {
	int index = 1;
	if (this->head == NULL) {
		cout << "SinglyLinkedList is empty!!! (Search Element)" << endl;
	}
	else {
		SNode* currentNode = new SNode;
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
void SinglyLinkedList::SortedSinglyList(int n) {
	
}
void SinglyLinkedList::DeleteAllElement() {
	if (this->head == NULL) {
		cout << "SinglyLinkedList is empty!!! (Delete All Element)" << endl;
		return;
	}
	SNode* currentNode = new SNode;
	currentNode = this->head;
	while (currentNode != NULL)
	{
		currentNode = currentNode->next;
		delete this->head;
		this->head = currentNode;
	}
	cout << "All elements have been deleted" << endl;
}
void SinglyLinkedList::Traverse() {
	if (this->head == NULL) {
		cout << "SinglyLinkedList is empty!!! (Traverse)" << endl;
		return;
	}
	SNode* currentNode = new SNode;
	currentNode = this->head;
	while (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
	cout << endl;
}
void SinglyLinkedList::ReverseTraverse() {
	if (this->head == NULL) {
		cout << "SinglyLinkedList is empty!!! (Reverse Traverse)" << endl;
		return;
	}
	SNode* prevNode = new SNode;
	SNode* nextNode = new SNode;
	prevNode = NULL;
	nextNode = NULL;
	while (!this->head == NULL)
	{
		nextNode = this->head->next;
		this->head->next = prevNode;
		prevNode = this->head;
		this->head = nextNode;
	}
	this->head = prevNode;
}
void SinglyLinkedList::InsertAfter(SNode* nodePos, int n) {
	if (nodePos == NULL) {
		cout << "The given previous node cannot be NULL (InsertAfter)" << endl;
		return;
	}
	SNode* newNode = new SNode;
	newNode->data = n;
	newNode->next = nodePos->next;
	nodePos->next = newNode;
}
int SinglyLinkedList::CountNodes() {
	int count = 0;
	if (this->head == NULL) {
		cout << "SinglyLinkedList is empty!!! (CountNodes)" << endl;
		return count;
	}
	else {
		SNode* currentNode = new SNode;
		currentNode = this->head;
		while (currentNode != NULL)
		{
			count++;
			currentNode = currentNode->next;
		}
		return count;
	}
}
void SinglyLinkedList::InsertAtPos(int pos, int n, int count) {
	int temp = 1;
	SNode* newNode = new SNode;
	newNode->data = n;
	if (pos == 1) {
		newNode->next = this->head;
		this->head = newNode;
	}
	else {
		if (pos == 0 || pos > count + 1) {
			cout << "There is no previous node left (InsertAtPos)" << endl;
			return;
		}
		SNode* prevNode = new SNode;
		prevNode = this->head;
		while (temp < pos - 1)
		{
			prevNode = prevNode->next;
			temp++;
		}
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}
}
void SinglyLinkedList::InsertBack(int n) {
	SNode* newNode = new SNode;
	newNode->data = n;
	newNode->next = NULL;
	if (this->head != NULL) {
		SNode* currentNode = new SNode;
		currentNode = this->head;
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
		return;
	}
	this->head = newNode;
}
void SinglyLinkedList::InsertFront(int n) {
	SNode* newNode = new SNode;
	newNode->data = n;
	newNode->next = this->head;
	this->head = newNode;
}
void SinglyLinkedList::CreateNode(int n) {
	SNode* newNode = new SNode;
	newNode->data = n;
	newNode->next = NULL;
	this->head = newNode;
}