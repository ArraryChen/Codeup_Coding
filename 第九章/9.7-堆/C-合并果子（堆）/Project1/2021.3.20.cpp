#include<cstdio>
#include<iostream>

using namespace std;

int n;
int heap[30010];

void downAdjust(int low, int high){

	int i = low, j = i * 2;
	while ( j <= high )
	{
		//注意是heap[j+1] < heap[j]
		if ( j+1 <= high && heap[j+1] < heap[j] )
		{
			j = j + 1;
		}

		//heap[i] > heap[j]
		if ( heap[i] > heap[j] )
		{
			swap(heap[i], heap[j]);
			i = j;
			j = i * 2;
		}
		else
			break;
	}
}

void createHeap(){

	for (int i = n/2; i >= 1; i--)
	{
		downAdjust(i, n); 
	}
}

int main(){

	while ( scanf("%d", &n) != EOF )
	{
		int sum = 0, tempN = n;

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &heap[i]);
		}

		createHeap();

		for (int i = 1; i <= n - 1; i++)
		{
			//temp:最小元素
			int temp = heap[1];

			//除去最小元
            heap[1] = heap[tempN--];
            
			//调堆
			downAdjust(1, tempN);
            
			//此时heap[1]:为之前的第二小元素,加上第一小元素(即完成了合并)
			heap[1] += temp;

			//加合并后的值加入sum
            sum += heap[1];

			//再次调堆
            downAdjust(1, tempN);
		}

		printf("%d\n", sum);
	}

	system("pause");
	return 0;
}
