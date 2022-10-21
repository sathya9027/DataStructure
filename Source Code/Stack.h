#include<iostream>
#include<stack>
using namespace std;
#define MAX 5
class Stack
{
private:
	stack<int> stk1;
	stack<int> stk2;
	int top;
	int* arr;				//dynamic array
	//int arr[MAX];			//static array
	int capacity;
	bool IsEmpty();
	bool IsFull();
	void Push(int n);
	void Pop();
	void Peek();
	void GetSize();
	void Display(stack<int> stk);
	void Traverse();
public:
	Stack();				//normal constructor
	Stack(int size);		//parameter constructor
	~Stack();
	void TypesOfStack();
	void TypesOfStackInSTL();
};

