#include "List.h"
List::List() {

}
List::~List() {

}
void List::TypesOfList() {
	cout << "*****Doubly Linked List (STL)*****" << endl;
	cout << "Push Front" << endl;
	for (int i = 0; i <= 3; i++)
	{
		list1.push_front(i + 10);
	}
	list1.push_front(14);
	list1.push_front(15);
	cout << "Push Front" << endl;
	for (int i = 0; i < 10; i++)
	{
		list2.push_front(i);
	}
	DisplayList(list1);
	DisplayList(list2);
	cout << endl << "Push Back" << endl;
	list1.push_back(16);
	list1.push_back(17);
	DisplayList(list1);
	cout << "Pop Front" << endl;
	list1.pop_front();
	DisplayList(list1);
	cout << endl << "Pop Back" << endl;
	list1.pop_back();
	DisplayList(list1);
	cout << endl << "Insert" << endl;
	it = list1.begin();
	//it++; //or advance or both
	advance(it, 2);
	list1.insert(it, 18);
	DisplayList(list1);
	cout << endl;
	list1.insert(it, 3, 19);
	DisplayList(list1);
	/*cout << endl << "Assign" << endl;
	list1.assign(7, 20);
	DisplayList(list1);*/
	cout << endl << "First Element : " << list1.front() << endl;
	cout << "Last Element : " << list1.back() << endl;
	cout << "Remove" << endl;
	list1.remove(11);
	list1.remove(22);
	DisplayList(list1);
	cout << endl << "Erase" << endl;
	it--;
	list1.erase(it);
	DisplayList(list1);
	list1.empty() ? cout << endl << "List is Empty " : cout << endl << "List is not Empty";
	cout << endl << "Size of the List : " << list1.size() << endl;
	cout << "Reverse" << endl;
	list1.reverse();
	DisplayList(list1);
	cout << endl << "Sorting" << endl;
	list1.sort();
	DisplayList(list1);
	cout << endl << "Swapping" << endl;
	list1.swap(list2);
	DisplayList(list1);
	cout << endl;
	DisplayList(list2);
	cout << endl << "Remove if" << endl;
	list1.remove_if([](int a) {return a < 5; });
	DisplayList(list1);
	cout << endl << "Splice" << endl;
	//list1.splice(list1.begin(),list2); //method 1
	//DisplayList(list1);
	//list2.splice(list2.begin(), list1, list1.begin());//method 2
	it1 = list1.begin();
	list2.splice(list2.begin(), list1, it1, list1.end());			//method 23
	DisplayList(list2);
	cout << endl << "Merge " << endl;
	list1.sort();
	list2.sort();
	list1.merge(list2);
	DisplayList(list1);
	cout << endl << "Clear " << endl;
	list2.clear();
	DisplayList(list2);
}
void List::DisplayList(list<int> lt)
{
	for (auto it = lt.begin(); it != lt.end(); it++)
	{
		cout << *it << " ";
	}
}