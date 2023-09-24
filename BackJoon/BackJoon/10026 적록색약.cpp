#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
char graph[100][100];
int visit[100][100][2];
int count1, count2;

int x_dir[4] = { -1,1,0,0 };
int y_dir[4] = { 0,0,-1,1 };

void BFS(int _x,int _y,int k)
{
	queue<pair<int,int>> queue_;
	queue_.push(make_pair(_x,_y));
	visit[_x][_y][k] = 1;

	while (!queue_.empty())
	{
		int x_ = queue_.front().first;
		int y_ = queue_.front().second;
		queue_.pop();
		for (int i = 0; i < 4; i++)
		{
			int X = x_ + x_dir[i];
			int Y = y_ + y_dir[i];
			if (X >= 0 && Y >= 0 && X < N && Y < N)
			{
				if (k == 0)
				{
					if (graph[X][Y] == graph[x_][y_] && visit[X][Y][k] == 0)
					{
						visit[X][Y][k] = 1;
						queue_.push(make_pair(X, Y));
					}
				}

				else //적록색약일때
				{
					
					if (graph[x_][y_] == 'R' || graph[x_][y_] == 'G')
					{
						if (graph[X][Y] != 'B' && visit[X][Y][k] == 0)
						{
							visit[X][Y][k] = 1;
							queue_.push(make_pair(X, Y));
						}
					}
					else if(graph[X][Y] == 'B'&& graph[x_][y_] == 'B'
						&& visit[X][Y][k] == 0)
					{
						visit[X][Y][k] = 1;
						queue_.push(make_pair(X, Y));
					}
				}


			}
		}
	}
	
}
int main()
{
	cin >> N;

	string str;
	count1 = 0;
	count2 = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			graph[i][j] = str[j];
			visit[i][j][0] = 0;
			visit[i][j][1] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j][0] == 0)
			{
				count1++;
				BFS(i,j,0);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j][1] == 0)
			{
				count2++;
				BFS(i,j,1);
			}
		}
	}
	cout << count1 << " " << count2 << endl;

	return 0;
}

