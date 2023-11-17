#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N,M;
vector<pair<int, int>> C;
vector<pair<int, int>> H;
int MIN=1000000;


int L(pair<int,int> H_, pair<int,int> C_)
{
	int A;
	if (H_.first > C_.first) A = H_.first - C_.first;
	else A = C_.first - H_.first;

	if (H_.second > C_.second) A += H_.second - C_.second;
	else A += C_.second - H_.second;

	return A;
}
void combi(int start, vector<int> b)
{
	if (b.size() == M) // M개 조합 됐을때.
	{
		int sum = 0;
		for (int i = 0; i < H.size(); i++)
		{
			int m = 1000000;
			for (int j = 0; j < M; j++)
			{
				int c = L(H[i], C[b[j]]);
				if (m >= c)
				{
					m = c;
				}
			}
			sum += m;
		}

		if (MIN >= sum)
		{
			MIN = sum;
		}
		return;
	}
	for (int i = start + 1; i < C.size(); i++)
	{
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
}
int main()
{
	cin >> N >> M;
	
	int a;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> a;
			if (a == 1) H.push_back({ r + 1,c + 1 });
			else if (a == 2) C.push_back({ r + 1,c + 1 });
		}
	}
	vector<int> b;
	combi(-1, b);
	cout << MIN;
	return 0;
}