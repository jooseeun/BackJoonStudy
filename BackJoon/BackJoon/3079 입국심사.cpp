#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
unsigned long long N, M;
unsigned long long T[100000];

unsigned long long low, mid, high;
unsigned long long BS()
{
	low = 1;
	high = M * T[0];
	unsigned long long people = 0;
	unsigned long long min = 0;

	while (low <= high)
	{
		people = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < N; i++)
		{
			people += mid / T[i]; // mid초동안 검사할 수 있는 최대 인원
		}
		if (people >= M)
		{
			if (min >= mid || min == 0)
			{
				min = mid;
			}
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return min;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> T[i];
	}
	sort(T, T + N);

	cout << BS();

	return 0;
}