#include "Vector.h"
Vector::Vector() {

}
Vector::~Vector() {

}
void Vector::TraverseIterator() {
	for (auto it = vect.cbegin(); it != vect.cend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void Vector::VectorUsingSTL() {
	for (int i = 0; i < marks.size(); i++)
	{
		cout << marks.at(i) << " ";
	}
	cout << endl;
	cout << "First element: " << marks.front() << endl;
	cout << "Last element: " << marks.back() << endl;
	cout << "Size of the Vector: " << marks.size() << endl;
	cout << "Max Size of the Vector: " << marks.max_size() << endl;
	if (marks.empty()) {
		cout << "Vector is empty!!!" << endl;
	}
	else {
		cout << "Vector is not empty!!!" << endl;
	}
	cout << "Before swaping" << endl;
	for (int i = 0; i < marks.size(); i++)
	{
		cout << marks.at(i) << " ";
	}
	cout << endl;
	cout << "After swaping" << endl;
	marks.swap(dupMarks);
	for (int i = 0; i < marks.size(); i++)
	{
		cout << marks.at(i) << " ";
	}
	cout << endl;
	cout << "Before pushback" << endl;
	TraverseIterator();
	for (int i = 6; i < 11; i++)
	{
		vect.push_back(i);
	}
	cout << "After pushback" << endl;
	TraverseIterator();
	vect.resize(8);
	cout << "After resize" << endl;
	TraverseIterator();
	vect.empty() ? cout << "vector is empty!!!" << endl : cout << "vector is not empty" << endl;
	cout << "Printing vector using iterator" << endl;
	for (auto it = vect.cbegin(); it != vect.cend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "Printing vector using reverse iterator" << endl;
	for (auto it = vect.crbegin(); it != vect.crend(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
	/*vect.assign(5, 10);
	Traverse();*/
	cout << "Deleting element" << endl;
	vect.pop_back();
	TraverseIterator();
	cout << "Insertion at begining" << endl;
	it = vect.begin();
	it = vect.insert(it, 0);
	TraverseIterator();
	cout << "Deletion at begining" << endl;
	delIt = vect.begin();
	delIt = vect.erase(delIt);
	TraverseIterator();
	/*cout << "Deleting all elements" << endl;
	vect.erase(vect.cbegin(), vect.cend());*/
	vect.empty() ? cout << "vector is empty!!!" << endl : cout << "vector is not empty" << endl;
	/*cout << "Clearing all element" << endl;
	vect.clear();
	vect.empty() ? cout << "vector is empty!!!" << endl : cout << "vector is not empty" << endl;*/
	cout << "Swaping two vectors" << endl;
	swap(vect, dupVect);
	TraverseIterator();
}