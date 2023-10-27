#include <iostream>
#include <string>

using namespace std;

int main()
{
	int A[26];
	string Ans;
	string N;
	cin >> N;
	for (int i = 0; i < 26; i++)
	{
		A[i] = 0;
	}
	for (int i = 0; i < N.length(); i++)
	{
		A[N[i] - 65]++;
	}

	if (N.length() % 2 == 0)
	{
		//Â¦¼ö
		for (int i = 0; i < 26; i++)
		{
			if (A[i] % 2 != 0)
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			for (int j = 0; j < A[i] / 2; j++)
			{
				Ans += (char)(i + 65);
			}
		}
		for (int i = 25; i >= 0; i--)
		{
			for (int j = 0; j < A[i] / 2; j++)
			{
				Ans+= (char)(i + 65);
			}
		}
	}
	else
	{
		int mid=-1;
		for (int i = 0; i < 26; i++)
		{
			if (A[i] % 2 != 0)
			{
				if (mid == -1)
				{
					mid = i;
					A[i] -= 1;
				}
				else
				{
					cout << "I'm Sorry Hansoo\n";
					return 0;
				}
			}
		}
		for (int i = 0; i < 26; i++)
		{
			for (int k = 0; k < A[i] / 2; k++)
			{
				Ans+= (char)(i + 65);
			}
		}

		Ans+=(char)(mid + 65);

		for (int i = 25; i >= 0; i--)
		{
			for (int j = 0; j < A[i] / 2; j++)
			{
				Ans+=(char)(i + 65);
			}
		}
	}
	cout << Ans;
	return 0;
}