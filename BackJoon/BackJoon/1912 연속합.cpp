#include <iostream>

using namespace std;

int n;
int Arr[100001];
int Val[100001];
int main()
{

	cin >> n;
	for (int i = 1; i < n+1; i++)
	{
		cin >> Arr[i];
	}
	Arr[0] = -2001;
	Arr[n+1] = -2001;
	Val[1] = Arr[1];
	
	for (int i = 2; i < n+1; i++)
	{
		if (Val[i - 1] + Arr[i] >= Arr[i])
		{
			Val[i] = Val[i - 1] + Arr[i];
		}
		else
		{
			Val[i] = Arr[i];
		}
		//Val[i] = max(Val[i-1] + Arr[i], Arr[i] + Arr[i + 1]);
	}
	int max_ = -2001;
	for (int i = 1; i < n+1; i++)
	{
		if (max_ <= Val[i])
		{
			max_ = Val[i];
		}
	}
	cout << max_;

	return 0;

}