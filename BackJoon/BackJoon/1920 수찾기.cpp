#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int A[100001];
int BS(int Num)
{
	int low, high, mid;
	low = 0;
	high = N - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] == Num)
		{
			return 1;
		}
		else if (A[mid] > Num)
		{
			high = mid - 1;
			
		}
		else if (A[mid] < Num)
		{
			low = mid + 1;

		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A, A+N);
	cin >> M;
	int b;
	for (int i = 0; i < M; i++)
	{
		cin >> b;
		cout << BS(b) << "\n";
	}

}