#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class ArrayVector
{
public:
	ArrayVector();
	int size() const;
	bool empty() const;
	int& operator[] (int i);
	int& at(int i) throw(out_of_range);
	void erase(int i);
	void insert(int i, const int& e);
	void reserve(int N);
	
	inline void StartMerge()
	{
		mergesort(n, A);
	}
	inline void StartQuick1()
	{
		QuickSort(A,0,n-1);
	}
	inline void StartQuick2()
	{
		QuickSort2(A, 0, n - 1);
	}
	void mergesort(int n, int S[]);
	void merge(int h, int m, int U[], int V[], int S[]);
	void QuickSort(int S[], int a, int b);
	void QuickSort2(int S[], int a, int b);
private:
	int capacity;
	int n;
	int* A;
};

