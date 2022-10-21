#include "ForwardList.h"
ForwardList::ForwardList() {

}
ForwardList::~ForwardList() {

}
void ForwardList::TypesOfForwardList() {
	cout << "*****Singly Linked List (STL)*****" << endl;
	cout <<"Inserting Front" << endl;
	this->list1.push_front(10);
	this->list1.push_front(20);
	this->Display(this->list1);
	this->list1.emplace_front(30);
	this->list1.emplace_front(40);
	this->Display(this->list1);
	this->list1.pop_front();
	cout << "Deleting Front" << endl;
	this->Display(this->list1);
	cout << "Inserting After" << endl;
	this->it = this->list1.insert_after(this->list1.begin(), 50);
	advance(this->it, 2);		//incrementing position by 2
	this->list1.emplace_after(this->it, 60);
	this->Display(this->list1);
	cout << "After Reversing List" << endl;
	this->list1.reverse();
	this->Display(this->list1);
	cout << "After Sorting element(s)" << endl;
	this->list1.sort();
	this->Display(this->list1);
	cout << "After Removing element(s)" << endl;
	this->list1.remove(50);		//element which is specified will be removed
	this->list1.remove_if([](int a) {return a > 30; });		//element(s) which is greater than20 will be removed
	this->Display(this->list1);
	cout << "After Erasing 'After' element(s)" << endl;
	this->list1.erase_after(this->list1.begin());
	this->Display(this->list1);
	cout << "After Assigning element(s) to list2" << endl;
	this->list2.assign({ 80,10,90,40 });
	this->Display(this->list2);
	cout << "After Adding two list(s)" << endl;
	this->list2.splice_after(this->list2.begin(), this->list1);
	this->Display(this->list2);
	cout << "After Assigning element(s) to list3" << endl;
	this->list3.assign({ 5,70 });
	this->Display(this->list3);
	cout << "After Swaping Two List(s)" << endl;
	this->list3.swap(this->list2);
	this->Display(this->list2);
	this->Display(this->list3);
	cout << "After Sorting element(s)" << endl;
	this->list2.sort();
	this->list3.sort();
	cout << "After Merging List" << endl;
	this->list3.merge(this->list2);
	this->Display(this->list3);
	cout << "After Clearing List" << endl;
	this->list3.clear();
	this->Display(this->list3);
}
void ForwardList::Display(forward_list<int> list) {
	for (auto it = list.begin(); it != list.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}