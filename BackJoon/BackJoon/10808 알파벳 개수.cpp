#include <iostream>
#include <string>

using namespace std;
int ans[26];
int main()
{
	for (int i = 0; i < 26; i++)
	{
		ans[i] = 0;
	}
	string S;
	cin >> S;
	for (int i = 0; i < S.length(); i++)
	{
		int a = S[i] - 97;
		ans[a]++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << ans[i] <<" ";
	}
	return 0;
}