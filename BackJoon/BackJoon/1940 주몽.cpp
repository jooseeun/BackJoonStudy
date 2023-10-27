#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A;
int main()
{
	int M,N;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}

	sort(A.begin(), A.end());
	int Ans=0;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = i+1; j < A.size(); j++)
		{
			if (A[i] + A[j] == M)
			{
				Ans++;
			}
		}
	}
	cout << Ans;
	return 0;
}