#include <iostream>
#include <vector>

using namespace std;

int low, high, mid;
int N, M;
int Marble[301];

int main()
{
	cin >> N >> M;
	vector<int> ans(M);
	
	for (int i = 0; i < N; i++)
	{
		cin>>Marble[i];
	}
	while (true)
	{
		int Div = N / M;
		vector<int> sum(M);
		int j = 0;
		for (int i = 0; i < M; i++)
		{
			int su = 0;
			for (int k = 0; k < Div; k++)
			{
				su += Marble[j];
				j++;
			}
			sum[i] = su;
		}
		
	}

}