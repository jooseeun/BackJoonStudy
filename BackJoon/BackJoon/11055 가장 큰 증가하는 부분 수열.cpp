#include <iostream>
#include <vector>
using namespace std;


int N;
int A[1001];
int Ans[1001];
int Max_;

int main()
{
	Max_ = 0;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> A[i];
		Ans[i] = A[i];
	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = i + 1; j < N + 1; j++)
		{
			if (A[i] < A[j])
			{
				Ans[j] = max(Ans[j], Ans[i] + A[j]);
				
			}
		}
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (Max_ < Ans[i])
		{
			Max_ = Ans[i];
		}
	}
	cout << Max_;
	return 0;
}