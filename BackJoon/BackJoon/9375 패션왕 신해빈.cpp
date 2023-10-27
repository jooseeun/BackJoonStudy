#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		map<string, int> m;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string A ,B;
			cin >> A >> B;
			m[B]++;
		}
		long long Ans = 1;
		for (const auto &c : m)
		{
			Ans *= ((long long)c.second + 1);
		}
		Ans -= 1;
		cout << Ans << endl;
	}
	return 0;
}