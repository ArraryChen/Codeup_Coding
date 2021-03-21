#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

const int maxn = 100010;
int heap[maxn], A[maxn], B[maxn], n;

void downAdjust(int low, int high){

	int i = low, j = i * 2;
	while ( j <= high )
	{
		if ( j+1 <= high && heap[j+1] > heap[j] )
		{
			j = j + 1;
		}

		if ( heap[j] > heap[i] )
		{
			swap(heap[j], heap[i]);
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

	for (int i = n; i > 1; i--)
	{
		swap(heap[i], heap[1]);
		downAdjust(1, i-1);
	}
}

int main(){

	while ( scanf("%d", &n) != EOF && n )
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &A[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &B[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			heap[i] = A[1] + B[i];
		}

		createHeap();

		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if ( A[i] + B[j] < heap[1] )
				{
					heap[1] = A[i] + B[j];
					downAdjust(1, n);
				}
				else
					break;
			}
		}

		heapSort();

		for (int i = 1; i <= n; i++)
		{
			printf("%d", heap[i]);
			if ( i < n )
				printf(" ");
			else
				printf("\n");
		}
	}
	system("pause");
	return 0;
}
