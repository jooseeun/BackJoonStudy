#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> A;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ')'&&A.empty() == 0)
        {
            if(A.top()=='(')
            {
                A.pop();
            }
        }
        else
        {
            A.push(s[i]);
        }
    }
    if(A.empty()==0)
    {
        answer = false;
    }
    else
    {
        answer = true; 
    }

    return answer;
}