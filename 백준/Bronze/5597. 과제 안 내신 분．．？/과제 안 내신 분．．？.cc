#include <string>
#include <vector>
#include <iostream>
using namespace std;

int A[30];
int main()
{
	int a;
	for (int i = 0; i < 28; i++)
	{
		cin >> a;
		A[a-1] = 1;	
	}
	for (int i = 0; i < 30; i++)
	{
		if (A[i] != 1) cout << i+1 << endl;
	}
	return 0;
}