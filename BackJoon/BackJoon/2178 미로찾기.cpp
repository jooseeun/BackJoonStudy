#include <iostream>
#include <queue>

int x_dir[4] = { -1, 1, 0, 0 };   // 상화좌우 x축 방향
int y_dir[4] = { 0, 0, -1, 1 };
int main()
{
	int M = 0, N = 0;
	std::queue<std::pair<int, int>> queue;

	std::cin >> N >> M;
	int graph[102][102];
	int Walk[102][102];
	int Check[102][102];

	for (int i = 0; i < N; i++)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = str[j] - '0';

			Walk[i][j] = 0;
			Check[i][j] = 0;
		}
	}
	queue.push(std::make_pair(0, 0));
	int count = 0;

	while (!queue.empty())
	{
		Walk[0][0] = 1; // 방문표시

		int x = queue.front().first;
		int y = queue.front().second;

		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int x_ = x + x_dir[i];
			int y_ = y + y_dir[i];

			if (0 <= x_ && x < N && 0 <= y_ && y_ < M)
			{
				if (graph[x_][y_] == 1 && Walk[x_][y_] == 0)
				{
					Walk[x_][y_] = 1; //방문함
					Check[x_][y_] = Check[x][y] + 1;
					queue.push(std::make_pair(x_, y_));
				}
			}
		}
	}
	std::cout << Check[N - 1][M - 1] + 1 << std::endl;
}