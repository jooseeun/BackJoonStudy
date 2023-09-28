#include <iostream>
#include <vector>

using namespace std;

int low, high, mid;
int N, M;
vector<int> Marble;

int BS(int _low , int _high)
{
	low = _low;
	high = _high;

	int min1 = 0;
	int min2 = 0;
	while (low <= high)
	{
		int sum1 = 0;
		int sum2 = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < mid; i++)
		{
			sum1 += Marble[i];
		}
		for (int i = mid; i < N; i++)
		{
			sum2 += Marble[i];
		}
		
	}
}
int main()
{
	cin >> N >> M;

	int val;
	for (int i = 0; i < N; i++)
	{
		cin >> val;
		Marble.push_back(val);
	}

	BS(0, N);
}