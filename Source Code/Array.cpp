#include "Array.h"
Array::Array() {
	this->InitVariables();
}
Array::~Array() {

}
void Array::InitVariables() {
	this->num = 5;
	this->capacity = sizeof(ar) / sizeof(ar[0]);
}
void Array::ArrayUsingSTL() {
	for (int i = 0; i < marks.size(); i++)
	{
		cout << marks.at(i) << " ";
	}
	cout << endl;
	cout << "First element: " << marks.front() << endl;
	cout << "Last element: " << marks.back() << endl;
	cout << "Size of the array: " << marks.size() << endl;
	cout << "Max Size of the array: " << marks.max_size() << endl;
	if (marks.empty()) {
		cout << "Array is empty!!!" << endl;
	}
	else {
		cout << "Array is not empty!!!" << endl;
	}
	cout << "Before swaping" << endl;
	marks.fill(20);
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
	cout << "Printing array using iterator" << endl;
	for (auto it = marks.cbegin(); it != marks.cend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "Printing array using reverse iterator" << endl;
	for (auto it = marks.crbegin(); it != marks.crend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void Array::TypesOfArrays() {
	cout << "Array size: " << this->capacity << endl;
	cout << "After creation: ";
	this->Traverse(this->ar, this->num);
	cout << "Total elements: " << this->num << endl;
	this->num = this->InsertBegin(this->ar, this->num, 60, this->capacity);	//insertion at start
	cout << "After insertion (beginning): ";
	this->Traverse(this->ar, this->num);
	cout << "Total elements: " << this->num << endl;
	this->num = this->InsertEnd(this->ar, this->num, 70, this->capacity);		//insertion at end
	cout << "After insertion (ending): ";
	this->Traverse(this->ar, this->num);
	this->num = InsertAfter(this->ar, this->num, 80, this->capacity, 3);		//insertion at after
	cout << "After insertion (after): ";
	this->Traverse(ar, num);
	num = InsertBefore(ar, num, 90, capacity, 3);		//insertion at before
	cout << "Before insertion (before): ";
	Traverse(ar, num);
	num = InsertAtPosition(ar, num, 100, capacity, 1);		//insertion at position
	cout << "Insertion (at position): ";
	Traverse(ar, num);
	num = UpdateElement(ar, num, 110, 0);		//insertion at update
	cout << "Insertion (update): ";
	Traverse(ar, num);
	num = DeleteBegin(ar, num);	//deletion at start
	cout << "Before deletion (beginning): ";
	Traverse(ar, num);
	num = DeleteEnd(ar, num);	//deletion at end
	cout << "After deletion (end): ";
	Traverse(ar, num);
	index = SearchElement(ar, num, 100);	//searching a element
	if (index == -1) {
		cout << "Element not found (search)" << endl;
	}
	else {
		cout << "Element found at Index: " << index << endl;
	}
	num = DeleteElement(ar, num, 90);	//deletion a element
	cout << "After deletion (element): ";
	Traverse(ar, num);
	cout << "After traverse(backward): ";
	BackwardTraverse(ar, num);		//backward traverse
}
int Array::InsertAfter(int a[], int n, int data, int cap, int index) {
	if (n >= cap) {
		cout << "Array is Full, Can't insert element (Insert After)" << endl;
		return n;
	}
	for (int i = (n - 1); i >= 0; i--)
	{
		if (i >= index) {
			a[i + 1] = a[i];
		}
	}
	a[index + 1] = data;
	return n + 1;
}
int Array::UpdateElement(int a[], int n, int data, int index) {
	a[index] = data;
	return n;
}
int Array::InsertBefore(int a[], int n, int data, int cap, int index) {
	if (n >= cap) {
		cout << "Array is Full, Can't insert element (Insert Before)" << endl;
		return n;
	}
	for (int i = (n - 1); i >= 0; i--)
	{
		if (i >= index - 1) {
			a[i + 1] = a[i];
		}
	}
	a[index - 1] = data;
	return n + 1;
}
int Array::InsertAtPosition(int a[], int n, int data, int cap, int index) {
	if (n >= cap) {
		cout << "Array is Full, Can't insert element (Insert At Position)" << endl;
		return n;
	}
	for (int i = (n - 1); i >= index; i--)
	{
		if (i >= index) {
			a[i + 1] = a[i];
		}
	}
	a[index] = data;
	return n + 1;
}
int Array::InsertBegin(int a[], int n, int data, int cap) {
	if (n >= cap) {
		cout << "Array is Full, Can't insert element (Insert Begin)" << endl;
		return n;
	}
	for (int i = (n - 1); i >= 0; i--)
	{
		a[i + 1] = a[i];
	}
	a[0] = data;
	return n + 1;
}
int Array::DeleteBegin(int a[], int n) {
	for (int i = 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	a[n - 1] = NULL;
	return n - 1;
}
int Array::DeleteEnd(int a[], int n) {
	a[n - 1] = NULL;
	return n - 1;
}
int Array::InsertEnd(int a[], int n, int data, int cap) {
	if (n >= cap) {
		cout << "Array is Full, Can't insert element (Insert End)" << endl;
		return n;
	}
	a[n] = data;
	return n + 1;
}
int Array::DeleteElement(int a[], int n, int data) {
	int del = SearchElement(a, n, data);
	if (del == -1) {
		cout << "Element not found (Delete Element)" << endl;
		return n;
	}
	for (int i = del; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	return n - 1;
}
int Array::SearchElement(int a[], int n, int data) {
	for (int i = 0; i < n; i++)
	{
		if (a[i] == data) {
			return i;
		}
	}
	return -1;
}
void Array::Traverse(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void Array::BackwardTraverse(int a[], int n) {
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}