#include <iostream>
#include <algorithm>
using namespace std;

bool Com(int i, int j)
{
	return j < i;
}

int main()
{
	int N, K;
	int Coin[11];
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> Coin[i];
	}

	sort(Coin, Coin+N, greater<>());
	int Sum = K;
	int Count = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = Sum / Coin[i];
		Sum -= temp * Coin[i];
		Count += temp;
	}

	cout << Count;
	return 0;
}