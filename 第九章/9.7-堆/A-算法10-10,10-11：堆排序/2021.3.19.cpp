//#include<cstdio>
//#include<iostream>
//
//using namespace std;
//
//const int maxn = 100010;
//
//int heap[maxn], n;
//
//void downAdjust(int low, int high){
//
//	//i:当前元素
//	//j:当前元素的子结点
//	int i = low, j = i * 2;
//
//	//存在子结点
//	while ( j <= high )
//	{
//		//若存在右儿子, 且右儿子值比左儿子大
//		if ( j + 1 <= high && heap[j+1] > heap[j] )
//		{
//			j = j + 1;
//		}
//
//		//将大值往堆顶调
//		if ( heap[j] > heap[i] )
//		{
//			swap(heap[j], heap[i]);
//			i = j;
//			j = i * 2;
//		}
//		else 
//			break;
//	}
//}
//
//void createHeap(){
//
//	for (int i = n/2; i >= 1; i--)
//	{
//		downAdjust(i, n);
//	}
//
//}
//
//void heapSort(){
//
//	//初始化堆
//	createHeap();
//	for (int i = n; i > 1; i--)
//	{
//		//建立的是大根堆, 每一轮把最大值调到堆顶, 之后再调至数组尾部(题目要求递增序)
//		swap(heap[i], heap[1]);
//
//		//重新调堆
//		downAdjust(1, i - 1);
//	}
//
//}
//
//int main(){
//
//	while ( scanf("%d", &n) != EOF ) 
//	{
//		//循环输入n个数
//		for (int i = 1; i <= n; i++)
//		{
//			scanf("%d", &heap[i]);
//		}
//	
//		//堆排序
//		heapSort();
//
//		//循环输出n个数
//		for (int i = 1; i <= n; i++)
//		{
//			printf("%d", heap[i]);
//
//			if ( i < n ) 
//				printf(" ");
//			else 
//				printf("\n");
//		}
//	}
//
//	system("pause");
//	return 0;
//}
