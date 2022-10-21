#include "CircularSLL.h"
CircularSLL::CircularSLL() {
	this->tail = NULL;
}
CircularSLL::~CircularSLL() {

}
void CircularSLL::TypesOfCircularSLL() {
	cout << "*****Circular (Singly Linked List)*****" << endl;
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Creating Node" << endl;
	this->CreateNode(10);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Inserting Node(s) Front" << endl;
	this->InsertFront(20);
	this->InsertFront(30);
	this->InsertFront(40);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Inserting Node(s) Back" << endl;
	this->InsertBack(50);
	this->InsertBack(60);
	this->InsertBack(70);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Inserting Node(s) After" << endl;
	this->InsertAfter(this->tail->next, 80);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Inserting Node(s) At Position" << endl;
	this->InsertAtPos(10, 90);
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
	cout << "After Deleting After" << endl;
	this->DeleteAfter(this->tail);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "After Deleting At Position" << endl;
	this->DeleteAtPos(1);
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
	cout << "Searching a element" << endl;
	this->SearchElement(20);
	cout << "Printing data in reverse" << endl;
	this->ReverseTraverse();
	this->Traverse();
	cout << "After Deleting All Elements" << endl;
	this->DeleteAllElement();
	this->Traverse();
	cout << "No of Nodes: " << this->CountNodes() << endl;
}
void CircularSLL::ReverseTraverse() {
	if (this->tail == NULL) {
		cout << "Circular SinglyLinkedList is empty!!! (Reverse Traverse)" << endl;
		return;
	}
	CSNode* prevNode = new CSNode;
	CSNode* nextNode = new CSNode;
	CSNode* currentNode = new CSNode;
	currentNode = tail->next;
	nextNode = currentNode->next;
	do
	{
		prevNode = currentNode;
		currentNode = nextNode;
		nextNode = currentNode->next;
		currentNode->next = prevNode;
	} while (currentNode != this->tail);
	nextNode->next = this->tail;
	this->tail = nextNode;
}
void CircularSLL::DeleteAllElement() {
	if (this->tail == NULL) {
		cout << "Circular SinglyLinkedList is empty!!! (Delete All Element)" << endl;
		return;
	}
	CSNode* currentNode = new CSNode;
	currentNode = this->tail->next;
	do
	{
		currentNode = currentNode->next;
		delete this->tail->next;
		this->tail->next = currentNode;
	} while (currentNode != this->tail);
	this->tail = NULL;
	delete this->tail;
	cout << "All elements have been deleted" << endl;
}
void CircularSLL::SearchElement(int n) {
	int index = 1;
	if (this->tail == NULL) {
		cout << "Circular SinglyLinkedList is empty!!! (Search Element)" << endl;
	}
	else {
		CSNode* currentNode = new CSNode;
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
void CircularSLL::DeleteAtPos(int pos) {
	if (this->tail == NULL) {
		cout << "Circular SinglyLinkedList is empty!!! (DeleteAfter)" << endl;
		return;
	}
	int temp = 1;
	CSNode* delNode = new CSNode;
	if (pos == 1) {
		delNode = this->tail->next;
		this->tail->next = delNode->next;
		if (delNode == this->tail) {
			this->tail = NULL;
			delete this->tail;
		}
	}
	else {
		if (pos == 0) {
			cout << "No node(s) left to delete (DeleteAtPos)" << endl;
			return;
		}
		CSNode* prevNode = new CSNode;
		prevNode = this->tail->next;
		while (temp < pos - 1)
		{
			prevNode = prevNode->next;
			temp++;
		}
		delNode = prevNode->next;
		prevNode->next = delNode->next;
		if (delNode == this->tail) {
			this->tail = prevNode;
		}
	}
	delete delNode;
}
void CircularSLL::DeleteAfter(CSNode* nodePos) {
	if (this->tail == NULL) {
		cout << "Circular SinglyLinkedList is empty!!! (DeleteAfter)" << endl;
	}
	else {
		if (tail->next == this->tail) {
			cout << "No next Node to Delete (DeleteAfter)" << endl;
		}
		else {
			CSNode* delNode = new CSNode;
			delNode = nodePos->next;
			nodePos->next = delNode->next;
			if (delNode == this->tail) {
				this->tail = nodePos;
			}
			delete delNode;
		}
	}
}
void CircularSLL::DeleteBack() {
	if (this->tail == NULL) {
		cout << "No node(s) left to delete (DeleteBack)" << endl;
	}
	else if (this->tail->next == this->tail) {
		delete this->tail;
		this->tail = NULL;
	}
	else {
		CSNode* prevNode = new CSNode;
		prevNode = this->tail;
		do
		{
			prevNode = prevNode->next;
		} while (prevNode->next != this->tail); 
		prevNode->next = this->tail->next;
		delete this->tail;
		this->tail = prevNode;
	}
}
void CircularSLL::DeleteFront() {
	if (this->tail == NULL) {
		cout << "No node(s) left to delete (DeleteFront)" << endl;
		return;
	}
	else if (this->tail->next == this->tail) {
		delete this->tail;
		this->tail = NULL;
		return;
	}
	CSNode* delNode = new CSNode;
	delNode = this->tail->next;
	this->tail->next = delNode->next;
	delete delNode;
}
void CircularSLL::InsertAtPos(int pos, int n) {
	int temp = 1;
	CSNode* newNode = new CSNode;
	newNode->data = n;
	if (pos == 1) {
		newNode->next = this->tail->next;
		this->tail->next = newNode;
	}
	else {
		if (pos == 0) {
			cout << "There is no previous node left (InsertAtPos)" << endl;
			return;
		}
		CSNode* prevNode = new CSNode;
		prevNode = this->tail->next;
		while (temp < pos - 1)
		{
			prevNode = prevNode->next;
			temp++;
		}
		newNode->next = prevNode->next;
		prevNode->next = newNode;
		if (prevNode == this->tail) {
			this->tail = this->tail->next;
		}
	}
}
int CircularSLL::CountNodes() {
	int count = 0;
	if (this->tail == NULL) {
		cout << "Circular SinglyLinkedList is empty!!! (CountNodes)" << endl;
		return count;
	}
	else {
		CSNode* currentNode = new CSNode;
		currentNode = this->tail->next;
		do
		{
			count++;
			currentNode = currentNode->next;
		} while (currentNode != this->tail->next);
		return count;
	}
}
void CircularSLL::InsertAfter(CSNode* nodePos, int n) {
	if (nodePos == NULL) {
		cout << "Circular SinglyLinkedList is empty!!! (InsertAfter)" << endl;
		return;
	}
	CSNode* newNode = new CSNode;
	newNode->data = n;
	newNode->next = nodePos->next;
	nodePos->next = newNode;
	if (nodePos == this->tail) {
		this->tail = this->tail->next;
	}
}
void CircularSLL::InsertBack(int n) {
	CSNode* newNode = new CSNode;
	newNode->data = n;
	if (this->tail == NULL) {
		newNode->next = newNode;
		this->tail = newNode;
		return;
	}
	newNode->next = this->tail->next;
	this->tail->next = newNode;
	this->tail = newNode;
}
void CircularSLL::InsertFront(int n) {
	CSNode* newNode = new CSNode;
	newNode->data = n;
	if (this->tail == NULL) {
		newNode->next = newNode;
		this->tail = newNode;
		return;
	}
	newNode->next = this->tail->next;
	this->tail->next = newNode;
}
void CircularSLL::CreateNode(int n) {
	CSNode* newNode = new CSNode;
	newNode->data = n;
	newNode->next = newNode;
	this->tail = newNode;
}
void CircularSLL::Traverse() {
	if (this->tail == NULL) {
		cout << "Circular (Singly Linked List) is Empty!!! (Traverse)" << endl;
		return;
	}
	CSNode* currentNode = new CSNode;
	currentNode = this->tail->next;
	do
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	} while (currentNode != this->tail->next);
	cout << endl;
}