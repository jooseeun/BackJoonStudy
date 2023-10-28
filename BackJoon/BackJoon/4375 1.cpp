#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	while (scanf_s("%d",&n)!=EOF)
	{
		int A = 1, B = 1;
		while (true)
		{
			if (A % n == 0)
			{
				cout << B << endl;
				break;
			}
			else
			{
				A = (A * 10) + 1;
				A %= n;
				B++;
			}
		}
	}
	return 0;
}