#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> M;
    vector<pair<string, int>> A;
    vector<string> answer;
    int L;
    for (int i = 0; i < record.size(); i++)
    {
        vector<string> k;
        string del = " ";
        long long pos = 0;
        string token = "";
        while ((pos = record[i].find(del)) != string::npos)
        {
            token = record[i].substr(0, pos);
            k.push_back(token);
            record[i].erase(0, pos + del.length());
        }
        k.push_back(record[i]);

        if (k[0] == "Leave")
        {
            A.push_back({ k[1],0 });
        }
        else
        {
            M.insert(make_pair(k[1], k[2]));
        }

        if (k[0] == "Enter")
        {
            map<string, string>::iterator it = M.find(k[1]);
            if (it != M.end())
            {
                it->second = k[2];
            }
            

            A.push_back({ k[1],1 });
        }

        else if (k[0] == "Change")
        {
            map<string, string>::iterator it = M.find(k[1]);
            it->second = k[2];
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i].second == 1)
        {
            map<string, string>::iterator it = M.find(A[i].first);
            answer.push_back(it->second + "님이 들어왔습니다.");
        }
        if (A[i].second == 0)
        {
            map<string, string>::iterator it = M.find(A[i].first);
            answer.push_back(it->second + "님이 나갔습니다.");
        }
    }

    return answer;
}
