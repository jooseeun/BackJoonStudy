#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//unique �� ���� ������ �پ��־�� �ߺ��� �����ϱ�
//������ sort�� �� ���� ��� �Ѵ�.
//�׸��� �ڿ� ���� �ֵ��� erase�� �����ؾߵȴ�.

int main()
{
	vector<int> s{ 4, 3, 3, 5, 1, 2, 3 };
	for (int i : s)
	{
		cout << i << " ";
	}
	cout << endl;
	sort(s.begin(), s.end());
	// ����
	for (int i : s )
	{
		cout << i << " ";
	}
	cout << endl;
	s.erase(unique(s.begin(), s.end()), s.end());
	// �ߺ� ����
	for (int i : s)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}