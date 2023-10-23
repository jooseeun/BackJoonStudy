#include <iostream>
#include <algorithm>

using namespace std;
int Length[9];

int main()
{
	int Sum=0;
	for (int i = 0; i < 9; i++)
	{
		cin >> Length[i];
		Sum += Length[i];
	}
	sort(Length, Length + 9);
	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			int a = Sum - Length[i] - Length[j];
			if (a == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
						cout << Length[k]<<endl;
				}
				return 0;
			}
		}
	}

}
