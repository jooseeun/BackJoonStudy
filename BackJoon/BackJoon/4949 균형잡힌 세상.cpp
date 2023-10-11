#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<string> ans;

int main()
{
	bool k = false;

	while (k==false)
	{
		stack<char> B;
		string A;
		bool C = false;
		while (C== false)
		{
			getline(cin,A);

			if (A == ".")
			{
				k = true;
				break;
			}

			for (int i = 0; i < A.length(); i++)
			{

				if (A[i] == '[')
				{
					B.push('[');
				}

				else if (A[i] == ']')
				{
					if (B.empty() == true || B.top() != '[')
					{
						B.push(']');
					}
					else
					{
						B.pop();
					}
				}

				else if (A[i] == '(')
				{
					B.push('(');
				}

				else if (A[i] == ')')
				{
					if (B.empty() == true || B.top() != '(')
					{
						B.push(')');
					}
					else
					{
						B.pop();
					}
				}



				if (A[i] == '.')
				{
					C = true;
					if (B.empty() == true)
					{
						ans.push_back("yes");
						break;
					}
					else
					{
						ans.push_back("no");
						break;
					}
				}

			}
		}

	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}