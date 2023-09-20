#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
int visit1_[1001];
int visit2_[1001];
queue<int> queue_;

int graph_[1001][1001];

void BFS(int _start)
{
	visit1_[_start] = 1;
	queue_.push(_start);
	cout << endl;
	cout << _start << " ";

	while (!queue_.empty())
	{
		int front_ = queue_.front();
		queue_.pop();

		for (int i = 1; i <= N; i++)
		{
			if (graph_[front_][i] == 1 && visit1_[i] == 0)
			{
				queue_.push(i);
				visit1_[i] = 1;
				cout << i << " ";
			}
		}
	}
}

void DFS(int _start)
{
	visit2_[_start] = 1;

	cout << _start << " ";

	for (int i = 1; i <= N; i++)
	{
		if (graph_[_start][i] == 1 && visit2_[i] == 0)
		{
			DFS(i);
		}
	}
}

int main()
{
	cin >> N >> M >> V;
	int first, second;
	for (int i = 1; i <= N; i++)
	{
		visit1_[i] = 0;
		visit2_[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> first >> second;
		graph_[first][second] = 1;
		graph_[second][first] = 1;

	}

	DFS(V);
	BFS(V);

	return 0;
}