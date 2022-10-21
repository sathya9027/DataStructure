#pragma once
#include <iostream>
using namespace std;
struct CDNode
{
	int data;
	CDNode* prev;
	CDNode* next;
};
class CircularDLL
{
private:
	CDNode* tail;
	int CountNodes();
	void Traverse();
	void CreateNode(int n);
	void InsertFront(int n);
	void InsertBack(int n);
	void InsertAfter(CDNode* prevNode, int n);
	void InsertBefore(CDNode* nextNode, int n);
	void DeleteFront();
	void DeleteBack();
	void DeleteAfter(CDNode* prevNode);
	void DeleteBefore(CDNode* nextNode);
	void SearchElement(int n);
	void ReverseTraverse();
	void DeleteAllElement();
public:
	CircularDLL();
	~CircularDLL();
	void TypesOfCircularDLL();
};

