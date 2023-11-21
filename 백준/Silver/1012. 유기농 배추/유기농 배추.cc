#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int graph[51][51];
int visit[51][51];
int x_dir[4] = { -1,1,0,0 };
int y_dir[4] = { 0,0,-1,1 };
int T, M, N, K;
vector<int> A;
void BFS(int x_, int y_)
{
	queue<pair<int, int>> q;
	q.push({ x_,y_ });
	visit[x_][y_] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int X = x + x_dir[i];
			int Y = y + y_dir[i];
			if (X >= 0 && X < M && Y >= 0 && Y < N)
			{
				if (graph[X][Y] == 1&& visit[X][Y] == 0)
				{
					q.push({ X,Y });
					visit[X][Y] = 1;
				}
			}

		}
	}
}
int main()
{
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		cin >> M >> N >> K;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				graph[i][j] = 0;
				visit[i][j] = 0;
			}
		}

		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			graph[x][y] = 1;
		}
		A.push_back(0);
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][j] == 1 && visit[i][j] == 0)
				{
					BFS(i, j);
					A[q]++;
				}
			}
		}
	}
	for (int i = 0; i < T; i++)
	{
		cout << A[i] << "\n";
	}


	return 0;
}