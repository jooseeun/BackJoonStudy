#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	string Name[151];
	int Ans[26];
	cin >> N;
	for (int i = 0; i < 26; i++)
	{
		Ans[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> Name[i];
		Ans[Name[i][0] - 97]++;
	}
	bool no = true;
	for (int i = 0; i < 26; i++)
	{
		if (Ans[i] >= 5)
		{
			cout << (char)(i+97);
			no = false;
		}

	}
	if (no == true)
	{
		cout << "PREDAJA";
	}
	return 0;
}