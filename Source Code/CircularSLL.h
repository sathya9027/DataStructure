#pragma once
#include <iostream>
using namespace std;
struct CSNode
{
	int data;
	CSNode* next;
};
class CircularSLL
{
private:
	CSNode* tail;
	int CountNodes();
	void Traverse();
	void CreateNode(int n);
	void InsertFront(int n);
	void InsertBack(int n);
	void InsertAfter(CSNode* nodePos, int n);
	void InsertAtPos(int pos, int n);
	void DeleteFront();
	void DeleteBack();
	void DeleteAfter(CSNode* nodePos);
	void DeleteAtPos(int pos);
	void SearchElement(int n);
	void DeleteAllElement();
	void ReverseTraverse();
public:
	CircularSLL();
	~CircularSLL();
	void TypesOfCircularSLL();
};

