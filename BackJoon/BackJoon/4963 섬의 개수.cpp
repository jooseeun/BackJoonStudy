#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int w, h;
int x_dir[8] = { -1,0,1,-1,1,-1,0,1 };
int y_dir[8] = { -1,-1,-1,0,0,1,1,1 };

int _graph[50][50];
int _visit[50][50];

vector<int> answer_;
queue<pair<int,int>> queue_;

void BFS()
{
	while (!queue_.empty())
	{
		int x_ = queue_.front().first;
		int y_ = queue_.front().second;
		queue_.pop();

		for (int i = 0; i < 8; i++)
		{
			int X = x_ + x_dir[i];
			int Y = y_ + y_dir[i];
			if (X >= 0 && Y >= 0 && X < h && Y < w)
			{
				if (_graph[X][Y] == 1 && _visit[X][Y] == 0)
				{
					queue_.push(make_pair(X, Y));
					_visit[X][Y] = 1;
				}
			}
		}

	}
}

void input()
{
	int _count = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> _graph[i][j];
			_visit[i][j] = 0;
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (_graph[i][j] == 1 && _visit[i][j] == 0)
			{
				queue_.push(make_pair(i, j));
				_visit[i][j] = 1;
				_count++;
				BFS();
			}
		}
	}
	answer_.push_back(_count);
}

int main()
{
	while (true)
	{
		cin >> w >> h;
		
		if (w == 0 && h == 0)
		{
			break;
		}
		else
		{
			input();
		}
	}

	for (int i = 0; i < answer_.size(); i++)
	{
		cout << answer_[i];
		if (i != answer_.size() - 1)
		{
			cout << endl;
		}
	}
	return 0;
}