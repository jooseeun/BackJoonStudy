#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
unsigned long long d;
vector<unsigned long long> vec;
vector<unsigned long long> length_;


void BS()
{
	unsigned long long low, high, mid, dol , min;
	low = 1;
	high = d; // 다삭제되었을때
	min = d;
	while (low<=high)
	{
		mid = (low + high) / 2; // 점프할 수 있는 최소거리의 최대값
		// 돌끼리 젤 가까운 애부터 없앤다.
		dol = 0;
		
		for (int i = 1; i < n; i++)
		{
			long a = vec[dol - 1] + vec[dol + 1];
			if (min >= vec[i])
			{
				min == vec[i];
				dol = i;
			}
		}

		vec[dol] = vec[dol-1]+ vec[dol + 1];

	}
}
int main()
{
	cin >> d >> n >> d;
	unsigned long long len;
	for (int i = 0; i < n; i++)
	{
		cin >> len;
		vec.push_back(len);
	}

	sort(vec.begin(), vec.end());

}

//섬  돌  돌  돌   돌     돌   땅 - 돌이 5개 틈은 6개 제거 2개
//2   11  14   17   21  25
//2  9    3   3    4    4