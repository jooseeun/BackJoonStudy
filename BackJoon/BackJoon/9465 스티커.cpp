#include <iostream>
#include <vector>

using namespace std;

long long Sticker[2][100001];
long long Score[2][100001];
vector <int> ans;
int main()
{
	int T, n;

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j < n+1; j++)
			{
				cin >> Sticker[i][j];
			}
		} 
		Score[0][0] = 0;
		Score[1][0] = 0;
		Score[0][1] = Sticker[0][1];
		Score[1][1] = Sticker[1][1];

		for (int i = 2; i < n + 1; i++)
		{
			Score[0][i] = max(Score[1][i - 1], Score[1][i - 2]) + Sticker[0][i];
			Score[1][i] = max(Score[0][i - 1], Score[0][i - 2]) + Sticker[1][i];
		}

		ans.push_back(max(Score[0][n], Score[1][n]));
	}

	for (int i = 0; i < T; i++)
	{
		cout << ans[i] << endl;

	}
	return 0;
}

