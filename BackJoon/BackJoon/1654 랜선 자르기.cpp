#include <iostream>
#include <vector>
using namespace std;

long long N, K;
vector<long long> KLan;
long long low, high, mid;
long long Max;

long long BS()
{
	Max = 0;
	low = 1;
	mid = (low + high) / 2;
	while (low <= high)
	{
		long long sum=0;

		for (int i = 0; i < K; i++)
		{
			if (KLan[i] >= mid)
			{
				sum += KLan[i] / mid;
			}
		}

		if (sum == N)
		{
			if (Max <= mid)
			{
				Max = mid;
			}
			low = mid + 1;

		}
		else if (sum < N)
		{
			high = mid - 1;
		}
		else if (sum > N)
		{
			low = mid + 1;
		}

		mid = (low + high) / 2;
	}

	if (Max <= mid)
	{
		Max = mid;
	}

	return Max;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K>>N;
	long long val;
	high = val=0;

	for (int i = 0; i < K; i++)
	{
		cin >> val;
		if (high <= val)
		{
			high = val;
		}
		KLan.push_back(val);
	}

	cout << BS();

	return 0;
}