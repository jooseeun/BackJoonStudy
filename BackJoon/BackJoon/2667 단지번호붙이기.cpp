#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int N;
int graph[25][25];
int visit[25][25];
vector<int> answer_;


int x_dir[4] = { -1,1,0,0 };
int y_dir[4] = { 0,0,1,-1 };

queue<pair<int, int>> queue_;

void BFS()
{
	int count_=1;
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
				if (graph[X][Y] == 1 && visit[X][Y] == 0)
				{
					visit[X][Y] = 1;
					count_ += 1;
					queue_.push(make_pair(X, Y));
				}
			}
		}
	}
	answer_.push_back(count_);
}
int main()
{
	cin >> N;
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int k = 0; k < N; k++)
		{
			graph[i][k] = str[k] - '0';
			visit[i][k] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			if (graph[i][k] == 1 && visit[i][k] == 0)
			{
				visit[i][k] = 1;
				queue_.push(make_pair(i, k));
				BFS();
			}
		}
	}
	sort(answer_.begin(), answer_.end());

	cout << answer_.size() << endl;
	for (int i = 0 ; i < answer_.size(); i++)
	{
		cout << answer_[i] << endl;
	}

	return 0;
}