#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

// ���� next_permutation
// ����� ���� ������������ �����ؼ� ����Ѵ�.

void PrintV(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[3] = { 1,3,2 };
	sort(a, a + 3);
	vector<int> v;
	for (int i = 0; i < 3; i++)
	{
		v.push_back(a[i]);
	}
	
	do
	{
		PrintV(v);
	} while (next_permutation(v.begin(),v.end()));

	cout << endl;

	do
	{
		PrintV(v);
	} while (next_permutation(a, a + 3));
	return 0;
}