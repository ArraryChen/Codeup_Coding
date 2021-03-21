#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 100010;

int n, num[maxn];

void downAdjust(int low, int high){

	int i = low, j = i * 2;
	while ( j <= high )
	{
		if ( j+1 <= high && num[j+1] > num[j] )
		{
			j = j + 1;
		}

		if ( num[j] > num[i] )
		{
			swap(num[j], num[i]);
			i = j;
			j = i * 2;
		}
		else
			break;
	}
}

void createHeap(){

	for (int i = n / 2; i > 0; i--)
	{
		downAdjust(i, n);
	}

}

void heapSort(){

	createHeap();
	for (int i = n; i > 1; i--)
	{
		swap(num[i], num[1]);
		downAdjust(1, i-1);
	}
}

int main(){
	while ( scanf("%d", &n) != EOF )
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
		}

		heapSort();

		for (int i = 1; i <= n; i++)
		{
			printf("%d", num[i]);
			if ( i < n )
				printf(" ");
			else
				printf("\n");
		}
	}

	system("pause");
	return 0;
}
