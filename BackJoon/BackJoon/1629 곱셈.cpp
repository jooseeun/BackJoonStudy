#include <iostream>

using namespace std;

long long A, B, C;
long long go(int a,int b) // _A�� _B��ŭ ���Ѱ�
{
	if (b == 1)
	{
		return a % C;
	}
	long long ret = go(a, b / 2);
	ret = (ret * ret) % C;
	if (b % 2 == 1) // Ȧ����� �ѹ� �� �����־�� �Ѵ�.
	{
		ret = (ret * a) % C;
	}
	return ret;
	
}
int main()
{
	//���Ѱ� ������ ����ִ´�.
	// ��ⷯ ������ �����÷ο�, �̸� ���ش�.
	cin >> A >> B >> C;
	cout << go(A, B);
	return 0;
}