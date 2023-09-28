#include <iostream>

using namespace std;

int main()
{
	int N;
	int M=-1;
	int count_ = 0;
	cin >> N;
	int num = N;
	
	while (N != M)
	{

		int k = num / 10 + num % 10;
		M = num % 10 * 10 + k % 10;

		num = M;
		count_++;

	}
	
	cout << count_;
	return 0;


}