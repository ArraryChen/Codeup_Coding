#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 100;

int n, r;
int P[maxn], hashTable[maxn] = {false};

void generate(int index, int head){

	if ( index == r + 1 )
	{
		int i;
		for (i = 1; i < r; i++)
		{
			printf("%d ", P[i]);
		}
		printf("%d\n", P[i]);
		return;
	}

	for (int i = head; i <= n; i++)
	{
		if ( hashTable[i] == false )
		{
			P[index] = i;
			hashTable[i] = true;
			generate(index + 1, i + 1);
			hashTable[i] = false;
		}
	}
}

int main(){

	scanf("%d %d", &n, &r);

	generate(1, 1);

	system("pause");
	return 0;
}
