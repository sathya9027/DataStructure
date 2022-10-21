#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Vector
{
private:
	vector<int> marks = { 70,80,90,50,60 };
	vector<int> dupMarks = { 70,80,90,50,10 };
	vector<int> vect = { 1,2,3,4,5 };
	vector<int> dupVect = { 4,2,2,1,5,9 };
	vector<int> :: iterator it, delIt;
	void TraverseIterator();
public:
	Vector();
	~Vector();
	void VectorUsingSTL();
};