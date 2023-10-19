#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K;
vector<pair<int, int>> node[20005];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//greater -> 오름차순 정렬됨
int val[20005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> K;
	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= V; i++)
	{
		val[i] = 300001;
	}
	val[K] = 0;
	pq.push(make_pair(0, K));//시작점 넣어줌
	while (!pq.empty())
	{
		int W = pq.top().first; //가중치 0
		int X = pq.top().second; //처음 K넣어준거 , 노드위치
		pq.pop();

		for (int i = 0; i < node[X].size(); i++)
		{
			int V = node[X][i].first;//현재 노드에서 연결된 애들 탐색 -> 연결된 노드
			int U = node[X][i].second;//가중치
		

			if (W + U < val[V])//원래있던 가중치값보다 이동해서 가는게 더 작다면
			{
				val[V] = W + U;
				pq.push(make_pair(W + U, V));
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (val[i] == 300001) 
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << val[i] << endl;
		}
	}
	return 0;
}