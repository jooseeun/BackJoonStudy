#include <string>
#include <map>
#include <iostream>
using namespace std;
map<int, int> A;
int main()
{
	int a , max_;
	max_ = 0;
	for (int i = 1; i <= 9; i++)
	{
		cin >> a;
		A.insert({ a,i });
		if (max_ < a) max_ = a;
	}
	map<int, int>::iterator K = A.find(max_);
	cout << max_<<"\n"<<K->second;
	
	return 0;
}