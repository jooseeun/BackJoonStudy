#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string	S;
	cin >> S;
	string check = S;
	reverse(check.begin(), check.end());
	if (check == S)
	{
		cout<<"1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}