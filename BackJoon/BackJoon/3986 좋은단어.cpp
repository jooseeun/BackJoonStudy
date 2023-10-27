#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int N;
	int Ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		stack<char> a;
		string k;
		cin >> k;
		for (int j = 0; j < k.length(); j++)
		{
			if (a.empty()!=1 && a.top() == k[j])
			{
				a.pop();
			}
			else
			{
				a.push(k[j]);
			}
		}
		if (a.empty() == 1)
		{
			Ans++;
		}
		
	}
	cout << Ans;
	return 0;
}