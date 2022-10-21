#pragma once
#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "ForwardList.h"
#include "List.h"
#include "CircularSLL.h"
#include "CircularDLL.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "UnorderedQLL.h"
#include "PriorityQLL.h"
#include "DequeDLL.h"
using namespace std;
class LinkedList
{
private:
	SinglyLinkedList singlyLinkedList;
	DoublyLinkedList doublyLinkedList;
	ForwardList forwardList;
	List list;
	CircularSLL circularSLL;
	CircularDLL circularDLL;
	StackLinkedList stackLinkedList;
	QueueLinkedList queueLinkedList;
	UnorderedQLL unorderQLL;
	PriorityQLL priorityQLL;
	DequeDLL dequeDLL;
public:
	LinkedList();
	~LinkedList();
	void TypesOfLinkedList();
};