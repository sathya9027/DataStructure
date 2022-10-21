#pragma once
#include <iostream>
#include <forward_list>
using namespace std;
class ForwardList
{
private:
	forward_list<int> list1, list2, list3;
	forward_list<int>::iterator it;
	void Display(forward_list<int> list);
public:
	ForwardList();
	~ForwardList();
	void TypesOfForwardList();
};

