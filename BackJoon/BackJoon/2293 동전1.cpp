#include <iostream>
#include <vector>

using namespace std;
int n, k;int coin[100];
int dp[10001];
int count_;
int main()
{
	count_ = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}
	dp[0] = 1; // 아무 동전도 선택하지 않은 경우도 하나의 경우의 수.
	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k];
	return 0;
	
}