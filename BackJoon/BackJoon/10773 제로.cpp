#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>

typedef struct NodeData
{
	int Data;

}Node;

typedef struct ArrayStack
{
	int Top;
	int Sum;
	Node* Nodes;
}Stack;

void Fuction(int Num, Stack** _stack)
{
	if (Num != 0)
	{

		(*_stack)->Nodes[(*_stack)->Top].Data = Num;
		(*_stack)->Top++;
		(*_stack)->Sum += Num;
	}
	else
	{
		--(*_stack)->Top;
		(*_stack)->Sum -= (*_stack)->Nodes[(*_stack)->Top].Data;
		(*_stack)->Nodes[(*_stack)->Top].Data = NULL;

	}

}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);


	int N;
	int Num;

	std::cin >> N;
	Stack* Mainstack = NULL;
	Mainstack = (Stack*)malloc(24 * N);
	Mainstack->Nodes = (Node*)malloc(8 * N);
	Mainstack->Top = 0;
	Mainstack->Sum = 0;

	for (int i = 0; i < N; i++)
	{
		std::cin >> Num;
		Fuction(Num, &Mainstack);
	}
	std::cout << Mainstack->Sum;

	free(Mainstack->Nodes);
	free(Mainstack);

	return 0;
}