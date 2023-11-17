#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N,M;
	cin >> N>>M;
	vector<int> K(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j <= b; j++)
		{
			K[j-1] = c;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << K[i]<< " ";
	}
	return 0;
}