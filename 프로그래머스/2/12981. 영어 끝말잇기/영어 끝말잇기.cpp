#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> Note;
    int A = 0;
    Note.push_back(words[0]);
    for(int b=0;b<words.size()/n;b++)
    {
        for(int i=0;i<n;i++)
        {
            if(((n*A) + i)==0) continue;
            string W = words[(n*A) + i];
            string P = Note[(n*A) + i-1];
            Note.push_back(W);
            
            if(P[P.length()-1]!=W[0])
            { 
                answer.push_back(i+1);
                answer.push_back(A+1);
                return answer;
                
            }
            for(int k=0;k<Note.size()-1;k++)
            {
                if(Note[k]==W)
                {
                    answer.push_back(i+1);
                    answer.push_back(A+1);
                    return answer;
                }

            }
        }
        A++;
        
    }
    if(answer.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}