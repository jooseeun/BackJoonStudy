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
	//�迭 �ʱ�ȭ
    Arr.StartMerge(); //Mergesort
	//Arr.StartQuick1(); //����Ʈ pivot ���� ��
	//Arr.StartQuick2(); // ����Ʈ pivot mid�� ����
	for (int i = 0; i < 8; i++)
	{
		cout << " " << Arr[i];
	}



	return 0;
}