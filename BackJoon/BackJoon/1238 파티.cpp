#include <iostream>
#include <vector>
#include <queue>

#define MAX 987654321

using namespace std;
vector<pair<int, int>> Stu[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>> pq;
int val[1001][1001];
int Wval[1001];
int N, X, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> X; 
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		Stu[a].push_back({ b,c });
	}
	for (int k = 1; k <= N; k++)
	{
		Wval[k] = MAX;
		for (int i = 1; i <= N; i++)
		{
			val[k][i] = MAX;
		}
	}
	
	
	for (int i = 1; i <= N; i++)
	{
		pq.push(make_pair(i,0));

		while (!pq.empty())
		{
			int NowN = pq.top().first;
			int NowW = pq.top().second;
			pq.pop();
			for (int j = 0; j < Stu[NowN].size(); j++)
			{
				int NextN = Stu[NowN][j].first;
				int NextW = Stu[NowN][j].second;

				if (NowW + NextW < val[i][NextN])
				{
					val[i][NextN] = NowW + NextW;
					pq.push({ NextN,val[i][NextN] });
				}
			}
		}
	}

	pq.push({ X,0 });
	while (!pq.empty())
	{
		int NowN = pq.top().first;
		int NowW = pq.top().second;
		pq.pop();
		for (int i = 0; i < Stu[NowN].size(); i++)
		{
			int NextN = Stu[NowN][i].first;
			int NextW = Stu[NowN][i].second;

			if (NowW + NextW < Wval[NextN])
			{
				Wval[NextN] = NowW + NextW;
				pq.push({ NextN,Wval[NextN] });
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		int A = val[i][X] + Wval[i];

		if (max < A && i!=X)
		{
			max = A;
		}
	}
	cout <<max;
	return 0;
}