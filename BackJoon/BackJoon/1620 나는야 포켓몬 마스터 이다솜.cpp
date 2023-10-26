#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<string, int> name;
map<int, string> name2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	string a;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		name.insert({ a,i });
		name2.insert({ i,a });
	}
	

	for (int i = 0; i < M; i++)
	{
		cin >> a;
		if (0 == atoi(a.c_str()))
		{
			map<string, int>::iterator it = name.find(a);
			cout << it->second<<'\n';

		}
		else
		{
			map<int, string>::iterator it = name2.find(atoi(a.c_str()));
			cout << it->second<<'\n';
		}
	}
	return 0;
}