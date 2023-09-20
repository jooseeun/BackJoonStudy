#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;

queue<pair<int,int>> queue_;

int graph_[1001][1001];

int count1_[1001][1001];
int count2_[1001][1001];

int visit1_[1001][1001];
int visit2_[1001][1001];

int broke_[1001][1001];

int x_dir[4] = { -1, 1, 0, 0 };   // 상화좌우 x축 방향
int y_dir[4] = { 0, 0, -1, 1 };

void BFS()
{
	visit1_[1][1] = 1;
	visit2_[1][1] = 1;
	count1_[1][1] = 1;
	count2_[1][1] = 1;
	queue_.push(make_pair(1, 1));
	int x_, y_;
	bool Stop = false;
	queue<pair<int, int>> q;
	while (!queue_.empty())
	{
		x_ = queue_.front().first;
		y_ = queue_.front().second;
		queue_.pop();
		Stop = false;
		
		for (int i = 0; i < 4; i++)
		{
			int X = x_ + x_dir[i];
			int Y = y_ + y_dir[i];

			if (1 <= X && X <= N && 1 <= Y && Y <= M)
			{
				if (broke_[x_][y_] == 0)//벽 안부셨을때
				{
					if (graph_[X][Y] == 0 && visit1_[X][Y] == 0)
					{
						count1_[X][Y] = count1_[x_][y_] + 1;
						queue_.push(make_pair(X, Y));
						visit1_[X][Y] = 1;
						visit2_[X][Y] = 1;
						broke_[X][Y] = broke_[x_][y_];
					}

					if (graph_[X][Y] == 1 && visit1_[X][Y] == 0
						&& broke_[x_][y_] == 0)
					{
						count1_[X][Y] = count1_[x_][y_] + 1;
						count2_[X][Y] = count1_[x_][y_] + 1;
						queue_.push(make_pair(X, Y));
						visit1_[X][Y] = 1;
						broke_[X][Y] = 1;
					}
				}
				else if(broke_[x_][y_] == 1) // 벽을 부셨을때
				{
					if (graph_[X][Y] == 0 && visit2_[X][Y] == 0)
					{
						count2_[X][Y] = count2_[x_][y_] + 1;
						queue_.push(make_pair(X, Y));
						visit2_[X][Y] = 1;
						broke_[X][Y] = broke_[x_][y_];
						
					}
				}
			}
		}
	}
	
	if (count1_[N][M] < count2_[N][M]
		&& count1_[N][M] != -1)
	{
		cout << count1_[N][M];
	}
	else
	{
		if (count2_[N][M] == -1 && count1_[N][M] != -1)
		{
			cout << count1_[N][M];
		}
		else
		{
			cout << count2_[N][M];

		}
	}
	
}

int main()
{
	cin >> N >> M;
	string input;
	
	for (int i = 1; i < N+1; i++)
	{
		cin >> input;
		for (int j = 1; j < M+1; j++)
		{
			graph_[i][j]= input[j-1] - '0';

			visit1_[i][j] = 0;
			visit2_[i][j] = 0;
			count1_[i][j] = -1;
			count2_[i][j] = -1;
			broke_[i][j] = 0;
		}
	}

	BFS();

	return 0;
}