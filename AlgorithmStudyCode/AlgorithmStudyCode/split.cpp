#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//C++ 에서는 지원하지 않아서 외워서 만들어서 구현해야됨
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
	string s = "안녕하세요 큰돌이는 킹갓제너럴 천재입니다. 정말이에요!", d = " ";
	vector<string> a = split(s, d);
	for (string b:a)
	{
		cout << b << endl;
	}
}