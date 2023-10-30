#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int N, a;
	priority_queue<int> Max;
	priority_queue<int, vector<int>, greater<>> Min;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (Max.size() > Min.size())
		{
			Min.push(v[i]);
		}
		else
		{
			Max.push(v[i]);
		}
		
		if(!Max.empty() && !Min.empty())
		{
			int a = Max.top();
			int b = Min.top();
			if (a > b)
			{
				Max.pop();
				Min.pop();

				Max.push(b);
				Min.push(a);
			}
		}
		cout << Max.top()<<"\n";
	}
}