#pragma once
#include <iostream>
using namespace std;
struct DNode
{
	int data;
	DNode* prev;
	DNode* next;
};
class DoublyLinkedList
{
private:
	DNode* head;
	int CountNodes();
	void CreateNode(int n);
	void Traverse();
	void InsertFront(int n);
	void InsertBack(int n);
	void InsertAfter(DNode* prevNode, int n);
	void InsertBefore(DNode* nextNode, int n);
	void DeleteFront();
	void DeleteBack();
	void DeleteAfter(DNode* prevNode);
	void DeleteBefore(DNode* nextNode);
	void SearchElement(int n);
	void ReverseTraverse();
	void DeleteAllElement();
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void TypesOfDoublyLinkedList();
};