#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string Str[51];
	for (int i = 0; i < N; i++)
	{
		cin >> Str[i];
	}
	int length = Str[0].length();
	vector<char> Ans;
	for (int i = 0; i < length; i++)
	{
		char ch = Str[0][i];
		char ans = ch;
		for (int j = 0; j < N; j++)
		{
			if (ch != Str[j][i])
			{
				ans = '?';
			}
		}
		Ans.push_back(ans);
	}

	for (int i = 0; i < Ans.size(); i++)
	{
		cout << Ans[i];
	}
	return 0;
}