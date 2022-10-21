#include "StackLinkedList.h"
StackLinkedList::StackLinkedList() {
	this->top = NULL;
}
StackLinkedList::~StackLinkedList() {

}
void StackLinkedList::TypesOfStack() {
	/*cout << "*****Stack Linked List*****" << endl;
	this->Traverse();
	cout << "After Push Operation" << endl;
	this->Push(10);
	this->Push(20);
	this->Push(30);
	this->Traverse();
	cout << "After Pop Operation" << endl;
	this->Pop();
	this->Traverse();
	cout << "After Checking Top Element" << endl;
	this->Peek();
	cout << "After Checking Size" << endl;
	this->GetSize();
	cout << "After Checking Stack Is Empty" << endl;
	if (this->IsEmpty()) {
		cout << "Stack Is Empty (TypesOfStack)" << endl;
	}
	else {
		cout << "Stack Is Not Empty (TypesOfStack)" << endl;
	}*/

	int choice, n;
	do
	{
		cout << "*****************************" << endl;
		cout << "Stack (Using Linked List)" << endl;
		cout << "1 - Push Item" << endl;
		cout << "2 - Pop Item" << endl;
		cout << "3 - Display Stack" << endl;
		cout << "4 - Top Element" << endl;
		cout << "5 - Stack Size" << endl;
		cout << "6 - Is Empty" << endl;
		cout << "7 - Exit" << endl;
		cout << "Enter the choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the item to push: ";
			cin >> n;
			this->Push(n);
			break;
		case 2:
			this->Pop();
			break;
		case 3:
			this->Traverse();
			break;
		case 4:
			this->Peek();
			break;
		case 5:
			this->GetSize();
			break;
		case 6:
			if (this->IsEmpty()) {
				cout << "Stack Is Empty (TypesOfStack)" << endl;
			}
			else {
				cout << "Stack Is Not Empty (TypesOfStack)" << endl;
			}
			break;
		case 7:
			break;
		default:
			cout << "Invalid Choice" << endl;
			break;
		}
	} while (choice != 7);
}
void StackLinkedList::Traverse() {
	if (this->IsEmpty()) {
		cout << "Stack Linked List is Empty (Traverse)" << endl;
		return;
	}
	SLLNode* currentNode = new SLLNode;
	currentNode = this->top;
	while (currentNode != NULL)
	{
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}
}
void StackLinkedList::GetSize() {
	int size = 0;
	if (this->IsEmpty()) {
		cout << "Stack Linked List is Empty (GetSize)" << endl;
		cout << "Size of the Stack: " << size << endl;
		return;
	}
	SLLNode* currentNode = new SLLNode;
	currentNode = this->top;
	while (currentNode != NULL)
	{
		size++;
		currentNode = currentNode->next;
	}
	cout << "Size of the Stack: " << size << endl;
}
void StackLinkedList::Peek() {
	if (this->IsEmpty()) {
		cout << "Stack Linked List is Empty (Peek)" << endl;
		return;
	}
	cout << "Top Element is: " << this->top->data << endl;
}
void StackLinkedList::Pop() {
	if (this->IsEmpty()) {
		cout << "Stack Linked List is Empty (Pop)" << endl;
		return;
	}
	SLLNode* delNode = new SLLNode;
	delNode = top;
	top = top->next;
	cout << delNode->data << " is popped (Pop)" << endl;
	delete delNode;
}
bool StackLinkedList::IsEmpty() {
	return this->top == NULL;
}
void StackLinkedList::Push(int n) {
	SLLNode* newNode = new SLLNode;
	newNode->data = n;
	newNode->next = top;
	this->top = newNode;
}