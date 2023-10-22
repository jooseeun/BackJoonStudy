#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//C++ ������ �������� �ʾƼ� �ܿ��� ���� �����ؾߵ�
vector<string> split(string input, string delimiter)
{
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos=input.find(delimiter)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

int main()
{
	string s = "�ȳ��ϼ��� ū���̴� ŷ�����ʷ� õ���Դϴ�. �����̿���!", d = " ";
	vector<string> a = split(s, d);
	for (string b:a)
	{
		cout << b << endl;
	}
}