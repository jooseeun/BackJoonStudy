#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 987654321
long N, M;
vector<pair<long, long>> Bus[1001];
long val[1001];
priority_queue< pair<long, long>,vector<pair<long, long>>, greater<pair<long, long>>> pq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	int a, b, c;
	int start, finish;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		Bus[a].push_back(make_pair(b, c));

	}
	cin >> start >> finish;
	for (int i = 0; i<=N;i++)
	{
		sort(Bus[i].begin(), Bus[i].end());

	}
	for (int i = 1; i <= N; i++)
	{
		val[i] = MAX;
	}
	val[start] = 0;
	pq.push(make_pair( start,0 ));

	while (!pq.empty())
	{
		
		long Y = pq.top().first;
		int W = pq.top().second;
		pq.pop();

		for (int i = 0; i < Bus[Y].size(); i++)
		{
			int Next = Bus[Y][i].first;
			long Weight = Bus[Y][i].second;
			if (Weight + W < val[Next])
			{
				val[Next] = Weight+W;
				pq.push(make_pair(Next,val[Next]));
			}
		
		}
	}

	cout << val[finish];

	return 0;
}