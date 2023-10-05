#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int M,N;
unsigned long long low, high, mid;
unsigned long long Max;

vector<pair<int, unsigned long long>> graph_[10001];
vector<unsigned long long> vec;
int visit_[10001];

int x_, y_;


bool BFS(unsigned long long mid) //내 짐 무게
{
	queue<int> q;
	for (int i = 0; i < N + 1; i++)
	{
		visit_[i] = 0;
	}
	visit_[x_] = 1;
	q.push(x_);
	while (!q.empty())
	{
		int X = q.front();
		q.pop();

		for (int i = 0; i < graph_[X].size(); i++)
		{
			int next = graph_[X][i].first;
			int cost = graph_[X][i].second;
			if (visit_[next] == 0 && cost != 0
				&& cost >= mid)//다리가 있고 방문을 안했을때
			{
				visit_[next] = 1;
				if (next == y_)
				{
					while (!q.empty())
					{
						q.pop();
					}
					return true;
				}
				q.push(next);
			}
		}
	}
	return false;
}
unsigned long long BS()
{
	mid = (low + high) / 2;
	Max = 0;
	bool a;
	while (low <= high)
	{
		mid = (low + high) / 2;
		a = BFS(mid);
		if (true == a)
		{
			for (int i = 0; i < vec.size(); i++)
			{
				if (mid == vec[i] && Max < mid)
				{
					Max = mid;
				}
			}

			low = mid + 1; //중량을 계속 키운다.
		}
		else
		{
			high = mid - 1;
		}
	}

	return Max;
}
int main()
{
	
	cin >> N >> M;

	int a, b;
	unsigned long long c;
	
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;

		graph_[a].push_back({ b, c });
		graph_[b].push_back({ a, c });
		vec.push_back(c);
	}

	sort(vec.begin(), vec.end());

	low = vec[0];
	high = vec[vec.size()-1];

	cin >> x_ >> y_;

	
	cout<< BS();

	return 0;
}