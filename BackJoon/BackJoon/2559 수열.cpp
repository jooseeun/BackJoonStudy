#include <iostream>
#include <vector>
using namespace std;
int N, K;
int Sum[100001];
int main()
{
	cin >> N >> K;
	int a;
	cin >> a;
	Sum[0] = a;
	for (int i = 1; i < N; i++)
	{
		cin >> a;
		Sum[i] = Sum[i - 1] + a;
	}
	int max = Sum[K-1];
	int k = 0;
	for (int i = K; i < N; i++)
	{
		k = Sum[i] - Sum[i-K];

		if (k >= max)
		{
			max = k;
		}
	}
	cout << max;
	return 0;
}