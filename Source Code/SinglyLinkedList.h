#pragma once
#include <iostream>
using namespace std;
struct SNode
{
	int data;
	SNode* next;
};
class SinglyLinkedList
{
private:
	SNode* head;
	int CountNodes();
	void Traverse();
	void ReverseTraverse();
	void InsertBack(int n);
	void InsertFront(int n);
	void InsertAfter(SNode* nodePos, int n);
	void InsertAtPos(int pos, int n, int count);
	void CreateNode(int n);
	void DeleteBackSinglePointer();
	void DeleteFront();
	void DeleteBack();
	void DeleteAfter(SNode* nodePos);
	void DeleteAtPos(int pos, int count);
	void SearchElement(int n);
	void DeleteAllElement();
	void SortedSinglyList(int n);
public:
	SinglyLinkedList();
	~SinglyLinkedList();
	void TypesOfSinglyLinkedList();
};

