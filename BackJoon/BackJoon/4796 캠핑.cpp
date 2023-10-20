#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> ans;
	int L, P, V;

	while (true)
	{
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
		{
			break;
		}
		else
		{
			int count_ = 0;
			int Day = V % P;
			int Week = V / P;

			count_ = Week * L;
			if (Day >= L)
			{
				count_ += L;
			}
			else
			{
				count_ += Day;
			}
			ans.push_back(count_);
		}
	}
	for (int i = 1; i <= ans.size(); i++)
	{
		cout << "Case " << i << ": " << ans[i - 1] << endl;
	}
	return 0;
}