#include "Stack.h"
Stack::Stack() {					//normal constructor
	this->top = -1;
	this->capacity = MAX;
}
Stack::Stack(int size) {			//parameter constructor
	this->arr = new int[size];
	this->top = -1;
	this->capacity = MAX;
}
Stack::~Stack() {
	delete[] arr;
}
void Stack::TypesOfStackInSTL() {
	cout << "*****Stack Using STL*****" << endl;
	cout << "After Push Operation" << endl;
	this->stk1.push(10);
	this->stk1.push(20);
	this->stk1.push(30);
	this->Display(this->stk1);
	cout << "After Pop Operation" << endl;
	this->stk1.pop();
	this->stk1.pop();
	this->Display(this->stk1);
	cout << "Size Of Stack: " << this->stk1.size() << endl;
	cout << "Top Element: " << this->stk1.top() << endl;
	if (this->stk1.empty()) {
		cout << "Stack is empty!!!" << endl;
	}
	else {
		cout << "Stack is not empty!!!" << endl;
	}
	cout << "After Emplace Operation" << endl;
	this->stk2.emplace(40);
	this->stk2.emplace(50);
	this->Display(stk2);
	cout << "After Swap Operation" << endl;
	this->stk1.swap(stk2);
	cout << "Printing Stk1" << endl;
	this->Display(stk1);
	cout << "Printing Stk2" << endl;
	this->Display(stk2);
}
void Stack::Display(stack<int> stk) {
	while (!stk.empty())
	{
		cout << stk.top() << endl;
		stk.pop();
	}
}
void Stack::TypesOfStack() {
	/*cout << "*****Stack*****" << endl;
	cout << "After Creation" << endl;
	this->Traverse();
	cout << "After Push Operation" << endl;
	this->Push(10);
	this->Push(20);
	this->Push(30);
	this->Push(40);
	this->Push(50);
	this->Push(60);
	this->Traverse();
	cout << "After Checking Stack Is Empty" << endl;
	if (this->IsEmpty()) {
		cout << "Stack Is Empty (TypesOfStack)" << endl;
	}
	else {
		cout << "Stack Is Not Empty (TypesOfStack)" << endl;
	}
	cout << "After Pop Operation" << endl;
	this->Pop();
	this->Traverse();
	cout << "After Checking Top Element" << endl;
	this->Peek();
	cout << "After Checking Size" << endl;
	this->GetSize();
	cout << "After Checking Stack Is Full" << endl;
	if (this->IsFull()) {
		cout << "Stack Is Full (TypesOfStack)" << endl;
	}
	else {
		cout << "Stack Is Not Full (TypesOfStack)" << endl;
	}*/

	int choice, n;
	do
	{
		cout << "*****************************" << endl;
		cout << "Stack (Using Array)" << endl;
		cout << "1 - Push Item" << endl;
		cout << "2 - Pop Item" << endl;
		cout << "3 - Display Stack" << endl;
		cout << "4 - Top Element" << endl;
		cout << "5 - Stack Size" << endl;
		cout << "6 - Is Empty" << endl;
		cout << "7 - Is Full" << endl;
		cout << "8 - Exit" << endl;
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
			if (this->IsFull()) {
				cout << "Stack Is Full (TypesOfStack)" << endl;
			}
			else {
				cout << "Stack Is Not Full (TypesOfStack)" << endl;
			}
			break;
		case 8:
			break;
		default:
			cout << "Invalid Choice" << endl;
			break;
		}
	} while (choice != 8);
	
}
void Stack::Traverse() {
	if (this->IsEmpty()) {
		cout << "Stack Is Empty (Traverse)" << endl;
		return;
	}
	cout << "Traversing..." << endl;
	for (int i = this->top; i >= 0; i--)
	{
		cout << this->arr[i] << endl;
	}
}
void Stack::GetSize() {
	if (this->IsEmpty()) {
		cout << "Stack Is Empty (GetSize)" << endl;
		return;
	}
	cout << "Size of the Stack: " << this->top + 1 << endl;
}
void Stack::Peek() {
	if (this->IsEmpty()) {
		cout << "Stack Is Empty (Peek)" << endl;
		return;
	}
	cout << "Top Element is: " << this->arr[this->top] << endl;
}
void Stack::Pop() {
	if (this->IsEmpty()) {
		cout << "Stack Is Empty (Pop)" << endl;
		return;
	}
	int temp;
	temp = arr[this->top];
	this->top--;
	cout << temp << " is popped (Pop)" << endl;
}
bool Stack::IsFull() {
	if (this->top == (this->capacity - 1)) {
		return true;
	}
	else {
		return false;
	}
}
void Stack::Push(int n) {
	if (this->IsFull()) {
		cout << "Stack Is Full (Push)" << endl;
		return;
	}
	this->top++;
	this->arr[this->top] = n;
	//cout << n << " is pushed (Push)" << endl;
}
bool Stack::IsEmpty() {
	if (this->top == -1) {
		return true;
	}
	else {
		return false;
	}
}