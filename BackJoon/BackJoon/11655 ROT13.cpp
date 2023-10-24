#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	getline(cin,S);

	char Ans[101];
	for (int i = 0; i < S.length(); i++)
	{
		
		if (S[i] >= 97 && S[i]<=122)
		{
			if (S[i] > 109)
			{
				Ans[i] = S[i] - 13;
			}
			else
			{
				Ans[i] = S[i] + 13;
			}
		}
		else if(S[i] >= 65 && S[i]<=90)
		{
			char a = S[i] + 13;
			if (a >= 91)
			{
				Ans[i] = a - 26;
			}
			else
			{
				Ans[i] = a;
			}
		}
		else
		{
			Ans[i] = S[i];
		}
	}
	for (int i = 0; i < S.length(); i++)
	{
		cout << Ans[i];
	}
	return 0;
}