#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string S;
	int N;
	int Name[101];
	cin >> N >> S;
	string F, L;
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '*')
		{
			F = S.substr(0, i);
			L = S.substr(i + 1, S.length() - i);
			break;
		}
	}
	
	for (int j = 0; j < N; j++)
	{
		string A;
		Name[j] = 1;
		cin >> A;
		int k = 0;
		for (int i = 0; i < A.length(); i++)
		{
			if (i < F.length())
			{
				if (A[i] != F[i])
				{
					Name[j] = 0;
					break;
				}
			}
			
		}
		if (Name[j]!=0 && A.length()-F.length() >= L.length())
		{
			A = A.substr(A.length() - L.length(), L.length());
		}
		else
		{
			Name[j] = 0;
		}
		for (int i = 0; i < A.length(); i++)
		{
			if (Name[j]!=0 && A[i]!=L[i])
			{
				Name[j] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (Name[i] == 1) {
			cout << "DA" << endl;
		}
		else
		{
			cout << "NE" << endl;
		}
	}
	return 0;
}