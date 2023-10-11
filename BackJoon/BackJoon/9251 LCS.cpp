#include <iostream>
#include <string>
using namespace std;


int dp[1001][1001];

int main()
{
	string First;
	string Second;

	cin >> First >> Second;

	for (int i = 0; i < First.length(); i++)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i < First.length(); i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= First.length(); i++)
	{
		for (int j = 1; j <= Second.length(); j++)
		{
			if (First[i-1] == Second[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[First.length()][Second.length()];
	
	return 0;

}