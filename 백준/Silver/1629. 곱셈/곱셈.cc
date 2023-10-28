#include <iostream>

using namespace std;

long long A, B, C;
long long go(int a,int b) // _A를 _B만큼 곱한거
{
	if (b == 1)
	{
		return a % C;
	}
	long long ret = go(a, b / 2);
	ret = (ret * ret) % C;
	if (b % 2 == 1) // 홀수라면 한번 더 곱해주어야 한다.
	{
		ret = (ret * a) % C;
	}
	return ret;
	
}
int main()
{
	//곱한걸 변수에 집어넣는다.
	// 모듈러 연산이 오버플로우, 미리 해준다.
	cin >> A >> B >> C;
	cout << go(A, B);
	return 0;
}