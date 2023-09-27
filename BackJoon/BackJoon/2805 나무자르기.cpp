#include <iostream>
#include <vector>
using namespace std;

long N,M;
vector<long> tree;
long answer;
long Max;
long low, mid, high;
void BS()
{
	low = 0;
	Max = 0;
	mid = (low + high) / 2;

	while (low <= high)
	{
		answer = 0;
		for (int i = 0; i < N; i++)
		{
			if (tree[i] - mid >= 0)
			{
				answer += tree[i] - mid;
			}
		}

		if (answer == M)
		{
			Max = mid;
			return;
		}
		else if (answer > M)
		{
			low = mid + 1;
		}
		else if (answer < M)
		{
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}
	Max = mid;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	long k;
	high = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> k;
		if (high < k) high = k;
		tree.push_back(k);
	}

	BS();
	cout << Max << "\n";
	return 0;
}