#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K;
vector<pair<int, int>> node[20005];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//greater -> �������� ���ĵ�
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
	pq.push(make_pair(0, K));//������ �־���
	while (!pq.empty())
	{
		int W = pq.top().first; //����ġ 0
		int X = pq.top().second; //ó�� K�־��ذ� , �����ġ
		pq.pop();

		for (int i = 0; i < node[X].size(); i++)
		{
			int V = node[X][i].first;//���� ��忡�� ����� �ֵ� Ž�� -> ����� ���
			int U = node[X][i].second;//����ġ
		

			if (W + U < val[V])//�����ִ� ����ġ������ �̵��ؼ� ���°� �� �۴ٸ�
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