#pragma once
#include <iostream>
#include <list>
using namespace std;
class List
{
private:
	list<int> list1, list2;
	list<int>::iterator it, it1;
	void DisplayList(list<int> lt);
public:
	List();
	~List();
	void TypesOfList();
};

