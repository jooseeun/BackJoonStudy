#include "code.h"

ArrayVector::ArrayVector()
	:capacity(0), n(0), A(NULL)
{

}

int ArrayVector::size() const
{
	return n;
}

bool ArrayVector::empty() const
{
	return size() == 0;
}

int& ArrayVector::operator[](int i)
{
	return A[i];
}

int& ArrayVector::at(int i) throw(out_of_range)
{
	if (i < 0 || i >= n)
		throw out_of_range("illegal index in function at()");
	return A[i];
}

void ArrayVector::reserve(int N)
{
	if (capacity >= N) return;
	int* B = new int[N];
	for (int i = 0; i < n; i++)
	{
		B[i] = A[i];
	}
	if (A != NULL) delete[] A;
	A = B;
	capacity = N;
}
void ArrayVector::insert(int i, const int& e)
{
	if (n >= capacity)
	{
		reserve(max(1, 2 * capacity));
	}
	for (int j = n-1; j >= i; j++)
	{
		A[j + 1] = A[j];
	}
	A[i] = e;
	n++;
}
void ArrayVector::erase(int i)
{
	for (int j = i+1; j < n; j++)
	{
		A[j - 1] = A[j];
	}
	n--;
}


//°úÁ¦
void ArrayVector::merge(int h, int m, int U[], int V[], int S[]) {
    int i = 0, j = 0, k = 0;

    while (i < h && j < m) {
        if (U[i] <= V[j]) {
            S[k++] = U[i++];
        }
        else {
            S[k++] = V[j++];
        }
    }

    while (i < h) {
        S[k++] = U[i++];
    }

    while (j < m) {
        S[k++] = V[j++];
    }
}

void ArrayVector::mergesort(int n, int S[]) {
    if (n > 1) {
        const int h = n / 2;
        const int m = n - h;

        int* U = new int[h];
        int* V = new int[m];

        for (int i = 0; i < h; i++) {
            U[i] = S[i];
        }
        for (int i = h; i < n; i++) {
            V[i - h] = S[i];
        }

        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);

        delete[] U;
        delete[] V;
    }
	
}
void ArrayVector::QuickSort(int S[], int a, int b)
{
    if (a >= b) return;

    int p = S[b];
    int l = a;
    int r = b - 1;

    while (l <= r)
    {
        while (l <= r && S[l] <= p)
        {
            l++;
        }
        while (l <= r && S[r] >= p)
        {
            r--;
        }
        if (l < r)
        {
            swap(S[l], S[r]);
        }
    }

    swap(S[l], S[b]);
    QuickSort(S, a, l - 1);
    QuickSort(S, l + 1, b);
}
void ArrayVector::QuickSort2(int S[], int a, int b)
{
    if (a >= b) return;

    int mid = (a + b) / 2; 
    int p = S[mid]; 

    int l = a;
    int r = b;

    while (l <= r)
    {
        while (S[l] < p)
        {
            l++;
        }
        while (S[r] > p)
        {
            r--;
        }
        if (l <= r)
        {
            swap(S[l], S[r]);
            l++;
            r--;
        }
    }

    QuickSort(S, a, r);
    QuickSort(S, l, b);
}
