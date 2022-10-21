#include "Deque.h"
Deque::Deque() {
	size = 0;
	front = -1;
	rear = -1;
	capacity = MAX;
}
Deque::~Deque() {

}
bool Deque::IsEmpty() {
	if (front == -1 && rear == -1) {
		return true;
	}
	else {
		return false;
	}
}
bool Deque::IsFull() {
	if ((rear + 1) % capacity == front) {
		return true;
	}
	else {
		return false;
	}
}
void Deque::InputRestrictedDeque() {
	int choice, n;
	do
	{
		cout << "1.) Insert (Front)" << endl;
		cout << "2.) Delete (Front)" << endl;
		cout << "3.) Delete (Rear)" << endl;
		cout << "4.) Front Element" << endl;
		cout << "5.) Rear Element" << endl;
		cout << "6.) Get Size" << endl;
		cout << "7.) Is Full" << endl;
		cout << "8.) Is Empty" << endl;
		cout << "9.) Traverse" << endl;
		cout << "10.) Exit" << endl;
		cout << "Enter the choice: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the element to insert: " << endl;
			cin >> n;
			InsertFront(n);
			break;
		case 2:
			DeleteFront();
			break;
		case 3:
			DeleteRear();
			break;
		case 4:
			FrontElement();
			break;
		case 5:
			RearElement();
			break;
		case 6:
			GetSize();
			break;
		case 7:
			if (IsFull()) {
				cout << "Deque Is Full (Input Restricted Deque)" << endl;
			}
			else {
				cout << "Deque Is Not Full (Input Restricted Deque)" << endl;
			}
			break;
		case 8:
			if (IsEmpty()) {
				cout << "Deque Is Empty (Input Restricted Deque)" << endl;
			}
			else {
				cout << "Deque Is Not Empty (Input Restricted Deque)" << endl;
			}
			break;
		case 9:
			Traverse();
			break;
		case 10:
			break;
		default:
			cout << "Invalid choice!!!" << endl;
			break;
		}
	} while (choice != 10);
}
void Deque::OutputRestrictedDeque() {
	int choice, n;
	do
	{
		cout << "1.) Insert (Front)" << endl;
		cout << "2.) Insert (Rear)" << endl;
		cout << "3.) Delete (Rear)" << endl;
		cout << "4.) Front Element" << endl;
		cout << "5.) Rear Element" << endl;
		cout << "6.) Get Size" << endl;
		cout << "7.) Is Full" << endl;
		cout << "8.) Is Empty" << endl;
		cout << "9.) Traverse" << endl;
		cout << "10.) Exit" << endl;
		cout << "Enter the choice: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the element to insert: " << endl;
			cin >> n;
			InsertFront(n);
			break;
		case 2:
			cout << "Enter the element to rear: " << endl;
			cin >> n;
			InsertRear(n);
			break;
		case 3:
			DeleteRear();
			break;
		case 4:
			FrontElement();
			break;
		case 5:
			RearElement();
			break;
		case 6:
			GetSize();
			break;
		case 7:
			if (IsFull()) {
				cout << "Deque Is Full (Output Restricted Deque)" << endl;
			}
			else {
				cout << "Deque Is Not Full (Output Restricted Deque)" << endl;
			}
			break;
		case 8:
			if (IsEmpty()) {
				cout << "Deque Is Empty (Output Restricted Deque)" << endl;
			}
			else {
				cout << "Deque Is Not Empty (Output Restricted Deque)" << endl;
			}
			break;
		case 9:
			Traverse();
			break;
		case 10:
			break;
		default:
			cout << "Invalid choice!!!" << endl;
			break;
		}
	} while (choice != 10);
}
void Deque::TypesOfCircularArray() {
	cout << "**DequeCircularArray**" << endl;
	this->Traverse();
	cout << "After Insert Front" << endl;
	//this->InsertFront(10);
	//this->InsertFront(20);
	//this->InsertFront(30);
	//this->InsertFront(40);
	//this->InsertFront(50);
	//this->InsertFront(60);
	this->Traverse();
	cout << "After Insert Rear" << endl;
	this->InsertRear(30);
	this->InsertRear(40);
	this->InsertRear(50);
	this->InsertRear(60);
	this->InsertRear(70);
	this->Traverse();/*
	cout << "After Delete Front" << endl;
	this->DeleteFront();
	this->DeleteFront();
	this->DeleteFront();
	this->DeleteFront();
	this->DeleteFront();
	this->Traverse();*/
	cout << "After Delete Rear" << endl;
	this->DeleteRear();
	this->Traverse();
	cout << "After Checking Front Element" << endl;
	this->Traverse();
	this->FrontElement();
	cout << "After Checking Rear Element" << endl;
	this->Traverse();
	this->RearElement();
	cout << "After Checking Size of the Array" << endl;
	this->Traverse();
	this->GetSize();
}
void Deque::TypesOfDeque() {
	int choice;
	do
	{
		cout << "1.) Input Restricted" << endl;
		cout << "2.) Output Restricted" << endl;
		cout << "3.) Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			InputRestrictedDeque();
			break;
		case 2:
			OutputRestrictedDeque();
			break;
		case 3:
			break;
		default:
			cout << "Invalid choice!!!" << endl;
			break;
		}
	} while (choice != 3);
}
void Deque::InsertFront(int n) {
	if (this->IsFull()) {
		cout << "Deque is Full (InsertFront)" << endl;
		return;
	}
	if (front == -1) {
		front = 0;
		rear = 0;
	}
	else if (front == 0) {
		front = capacity - 1;
	}
	else {
		front = front - 1;
	}
	arr[front] = n;
	size++;
	cout << "Front (Insert Front) :" << front << endl;
	cout << "Rear (Insert Front) :" << rear << endl;
}
void Deque::DeleteFront() {
	if (this->IsEmpty()) {
		cout << "Deque is Empty (Delete Front)" << endl;
		return;
	}
	int temp;
	temp = front;
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == capacity - 1) {
		front = 0;
	}
	else {
		front = front + 1;
	}
	size--;
	cout << arr[temp] << " is deleted" << endl;
	cout << "Front (Delete Front) :" << front << endl;
	cout << "Rear (Delete Front) :" << rear << endl;
}
void Deque::InsertRear(int n) {
	if (this->IsFull()) {
		cout << "Deque is Full (InsertRear)" << endl;
		return;
	}
	if (front == -1) {
		front = 0;
		rear = 0;
	}
	else if (rear == capacity - 1) {
		rear = 0;
	}
	else {
		rear = rear + 1;
	}
	size++;
	arr[rear] = n;
	cout << "Front (Insert Rear) :" << front << endl;
	cout << "Rear (Insert Rear) :" << rear << endl;
}
void Deque::DeleteRear() {
	if (this->IsEmpty()) {
		cout << "Deque is Empty (Delete Rear)" << endl;
		return;
	}
	int temp;
	temp = rear;
	if (rear == front) {
		front = -1;
		rear = -1;
	}
	else if (rear == 0) {
		rear = capacity - 1;
	}
	else {
		rear = rear - 1;
	}
	cout << arr[temp] << " is deleted" << endl;
	size--;
	cout << "Front (Delete Rear) :" << front << endl;
	cout << "Rear (Delete Rear) :" << rear << endl;
}
void Deque::FrontElement() {
	if (this->IsEmpty()) {
		cout << "Deque is Empty (FrontElement)" << endl;
		return;
	}
	cout << "Front Element: " << arr[front] << endl;
}
void Deque::RearElement() {
	if (this->IsEmpty()) {
		cout << "Deque is Empty (RearElement)" << endl;
		return;
	}
	cout << "Rear Element: " << arr[rear] << endl;
}
void Deque::GetSize() {
	if (this->IsEmpty()) {
		cout << "Deque is Empty (GetSize)" << endl;
		return;
	}
	cout << "Size of the Deque: " << size << endl;
}
void Deque::Traverse() {
	if (this->IsEmpty()) {
		cout << "Deque is Empty (Traverse)" << endl;
		return;
	}
	int i = 0;
	for (i = front; i != rear; i = (i + 1) % capacity) {
		cout << arr[i] << " ";
	}
	cout << arr[i] << endl;
}