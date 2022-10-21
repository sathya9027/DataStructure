#pragma once
#include <iostream>
#include <array>
using namespace std;
class Array {
private:
	int num, capacity, index;
	int ar[10] = { 10, 20, 30, 40, 50 };
	array<int, 5> marks = { 70,80,90,50,60 };
	array<int, 5> dupMarks = { 70,80,90,50,60 };
	void InitVariables();
	void Traverse(int a[], int n);
	void BackwardTraverse(int a[], int n);
	int InsertBegin(int a[], int n, int data, int cap);
	int DeleteBegin(int a[], int n);
	int DeleteEnd(int a[], int n);
	int InsertEnd(int a[], int n, int data, int cap);
	int DeleteElement(int a[], int n, int data);
	int SearchElement(int a[], int n, int data);
	int InsertAfter(int a[], int n, int data, int cap, int index);
	int InsertBefore(int a[], int n, int data, int cap, int index);
	int InsertAtPosition(int a[], int n, int data, int cap, int index);
	int UpdateElement(int a[], int n, int data, int index);
public:
	Array();
	~Array();
	void TypesOfArrays();
	void ArrayUsingSTL();
};