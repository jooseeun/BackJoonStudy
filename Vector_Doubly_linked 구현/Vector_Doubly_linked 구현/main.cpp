#include "code.h"
using namespace std;

int main()
{
	int A[8] = {21, 10, 12, 20, 25, 13, 15, 22};
	ArrayVector Arr;
	Arr.reserve(8);
	for (int i = 0; i < 8; i++)
	{
		Arr.insert(i, A[i]);
	}
	//배열 초기화
    Arr.StartMerge(); //Mergesort
	//Arr.StartQuick1(); //퀵소트 pivot 제일 끝
	//Arr.StartQuick2(); // 퀵소트 pivot mid로 잡음
	for (int i = 0; i < 8; i++)
	{
		cout << " " << Arr[i];
	}



	return 0;
}