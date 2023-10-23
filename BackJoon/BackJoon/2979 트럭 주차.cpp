#include <iostream>
using namespace std;

int Tem[3][2];
int main()
{
	int A, B, C;
	int Count_ = 0;
	int D[4];
	int Ans=0;
	bool Start = false;
	cin >> A >> B >> C;
	D[0] = 0;
	D[1] = A;
	D[2] = B;
	D[3] = C;
	for (int i = 0; i < 3; i++)
	{
		cin >> Tem[i][0] >> Tem[i][1];
	}

	for (int j = 1; j <= 100; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (j == Tem[i][0])
			{
				Start = true;
				Count_+=1;
			}
			if (j == Tem[i][1])
			{
				Count_-=1;
			}
		}
		Ans += D[Count_]*Count_;
	}

	cout << Ans;
	return 0;
}