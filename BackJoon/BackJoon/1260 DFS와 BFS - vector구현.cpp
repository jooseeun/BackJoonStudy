#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
int visit1_[1001];
int visit2_[1001];
queue<int> queue_;
vector<pair<int, int>> graph_;

void BFS(int _start)
{
	visit1_[_start] = 1;
	queue_.push(_start);
	cout << endl;

	while (!queue_.empty())
	{
		int front_ = queue_.front();
		cout << queue_.front() << " ";
		queue_.pop();

		for (int i = 0; i < M; i++)
		{
			if (graph_[i].first == front_ && visit1_[graph_[i].second] == 0
				&& graph_[i].second != front_)
			{
				visit1_[graph_[i].second] = 1;
				queue_.push(graph_[i].second);
			}
			else if (graph_[i].second == front_ && visit1_[graph_[i].first] == 0
				&& graph_[i].first != front_)
			{
				visit1_[graph_[i].first] = 1;
				queue_.push(graph_[i].first);
			}
		}
	}
}

void DFS(int _start)
{
	visit2_[_start] = 1;

	cout << _start << " ";

	for (int i = 0; i < M; i++)
	{
		if (graph_[i].first == _start && visit2_[graph_[i].second] == 0
			&& graph_[i].second != _start)
		{
			DFS(graph_[i].second);
		}
		if (graph_[i].second == _start && visit2_[graph_[i].first] == 0
			&& graph_[i].first != _start)
		{
			DFS(graph_[i].first);
		}
	}

}

int main()
{
	cin >> N >> M >> V;
	int first, second;
	for (int i = 0; i < 1001; i++)
	{
		visit1_[i] = 0;
		visit2_[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> first >> second;
		if (first < second)
		{
			graph_.push_back(make_pair(first, second));
		}
		else
		{
			graph_.push_back(make_pair(second, first));
		}
	}


	sort(graph_.begin(), graph_.end());

	DFS(V);
	BFS(V);

	return 0;
}