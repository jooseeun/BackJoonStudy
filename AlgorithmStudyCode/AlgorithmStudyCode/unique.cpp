#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//unique 는 같은 수끼리 붙어있어야 중복을 제거하기
//때문에 sort와 꼭 같이 써야 한다.
//그리고 뒤에 남은 애들을 erase로 삭제해야된다.

int main()
{
	vector<int> s{ 4, 3, 3, 5, 1, 2, 3 };
	for (int i : s)
	{
		cout << i << " ";
	}
	cout << endl;
	sort(s.begin(), s.end());
	// 정렬
	for (int i : s )
	{
		cout << i << " ";
	}
	cout << endl;
	s.erase(unique(s.begin(), s.end()), s.end());
	// 중복 제거
	for (int i : s)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}