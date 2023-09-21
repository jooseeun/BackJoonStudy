#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<pair<int,  int>> answer;
	int T, a, b;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		answer.push_back(make_pair(a, b));
	}

	for (int i = 0; i < T; i++)
	{
		unsigned long long tem = answer[i].first;

		int sem = answer[i].second;
		sem = sem % 4 + 4;
		for (int k = 1; k < sem; k++)
		{
			tem = (tem * answer[i].first) % 10;
		}

		if (tem == 0)
		{
			tem = 10;
		}
		
		cout << tem;

		if (i != T - 1)
		{
			cout << endl;
		}
	}
	return 0;
}