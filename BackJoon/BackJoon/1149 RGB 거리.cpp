#include <iostream>

using namespace std;


int N;
int House[1001][3];
int Min[1001][3];

int main()
{
	cin >> N;
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> House[i][j];
		}
	}
	// °Ë»ç (1,2 1,3) (2,3 2,1) (3,1 3,3)
	Min[0][0] = 0;
	Min[0][1] = 0;
	Min[0][2] = 0;
	Min[1][0] = House[1][0];
	Min[1][1] = House[1][1];
	Min[1][2] = House[1][2];


	for (int i = 2; i < N+1; i++)
	{
		Min[i][0] = min(Min[i-1][1], Min[i-1][2]) + House[i][0];
		Min[i][1] = min(Min[i-1][0], Min[i-1][2]) + House[i][1];
		Min[i][2] = min(Min[i-1][0], Min[i-1][1]) + House[i][2];
	}
	int aa = min(Min[N][0], Min[N][1]);

	cout << min(Min[N][2], aa) << endl;

	return 0;
}