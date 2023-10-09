#include <iostream>
#include <vector>
using namespace std;


int N;
int A[1001];
int Ans[1001];
int Max_;

int main()
{
	Max_ = 1;
	cin >> N;
	for (int i = 1; i < N+1; i++)
	{
		cin >> A[i];
		Ans[i] = 1;
	}
	
	for (int i = 1; i < N+1; i++)
	{
		for (int j = i+1; j < N+1; j++)
		{
			if (A[i] > A[j])
			{
				Ans[j] = max(Ans[j], Ans[i] + 1);
				if (Max_ < Ans[j])
				{
					Max_ = Ans[j];
				}
			}
		}
	}

	cout << Max_;
	return 0;
}