#include<cstdio>
#include<iostream>

using namespace std;

int N, Count = 0;

//111000 | 110100 | 101100 | 101010 | 110010

void BFS(int num, int push, int pop){

	if ( push == N && pop == N )
	{
		Count++;
		return;
	}
	if ( push < N )
	{
		BFS(num + 1, push + 1, pop);
	}
	if ( pop < N && num > 0 )
	{
		BFS(num - 1, push, pop + 1);
	}
}

int main(){

	while ( scanf("%d", &N) != EOF )
	{
		Count = 0;

		BFS(0, 0, 0);
	
		printf("%d\n", Count);
	}

	system("pause");
	return 0;
}

