#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// round(숫자) : 반올림
// ceil(숫자) : 올림
// floor(숫자) : 내림


using namespace std;
int N;
int K[8001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<int> A(N);
	double Sum_=0.0; 
	for (int i = 0; i < 8001; i++)
	{
		K[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];

		K[A[i] + 4000] += 1;
		Sum_ += A[i];
	}
	int mid = round(Sum_ / N);
	if (mid == -0)
	{
		mid = 0;
	}
	cout << mid << endl;
	sort(A.begin(), A.end());

	cout << A[N / 2]<<endl;
	int max_ = 0;
	int Ans_ = 0;
	int count_ = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (max_ < K[i])
		{
			count_ = 1;
			max_ = K[i];
			Ans_ = i - 4000;
		}
		else if (max_ == K[i] && count_ == 1)
		{
			Ans_ = i - 4000;
			count_++;
		}
	}
	cout << Ans_  << endl;
	cout << A[N - 1] - A[0] << endl;

	return 0;

}