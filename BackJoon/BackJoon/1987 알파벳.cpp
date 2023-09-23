#include <iostream>
#include <stack>

using namespace std;

int R, C;
int count_[20][20];
char graph_[20][20];
int alpha_[26];

int x_dir[4] = { -1,1,0,0 };
int y_dir[4] = { 0,0,-1,1 };

int max_;
void DFS(int x_,int y_)
{
	alpha_[(int)(graph_[x_][y_])-65]++;

	for (int i = 0; i < 4; i++)
	{
		int X = x_ + x_dir[i];
		int Y = y_ + y_dir[i];
		if (X >= 0 && Y >= 0 && X < R && Y < C)
		{
			if (alpha_[(int)(graph_[X][Y]) - 65] == 0)
			{
				count_[X][Y] = count_[x_][y_] + 1;

				if (max_ <= count_[X][Y])
				{
					max_ = count_[X][Y];
				}

				DFS(X, Y);
			}
		}
	}
	alpha_[(int)(graph_[x_][y_]) - 65]--;
}
int main()
{
	cin >> R >> C;
	string str;
	for (int i = 0; i < R; i++)
	{
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			graph_[i][j] = str[j];
			count_[i][j] = 0;
		}
	}
	max_ = 1;
	count_[0][0] = 1;
	DFS(0,0);
	cout << max_;

	return 0;
}