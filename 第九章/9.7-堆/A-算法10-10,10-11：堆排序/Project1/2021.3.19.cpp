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
//	//i:��ǰԪ��
//	//j:��ǰԪ�ص��ӽ��
//	int i = low, j = i * 2;
//
//	//�����ӽ��
//	while ( j <= high )
//	{
//		//�������Ҷ���, ���Ҷ���ֵ������Ӵ�
//		if ( j + 1 <= high && heap[j+1] > heap[j] )
//		{
//			j = j + 1;
//		}
//
//		//����ֵ���Ѷ���
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
//	//��ʼ����
//	createHeap();
//	for (int i = n; i > 1; i--)
//	{
//		//�������Ǵ����, ÿһ�ְ����ֵ�����Ѷ�, ֮���ٵ�������β��(��ĿҪ�������)
//		swap(heap[i], heap[1]);
//
//		//���µ���
//		downAdjust(1, i - 1);
//	}
//
//}
//
//int main(){
//
//	while ( scanf("%d", &n) != EOF ) 
//	{
//		//ѭ������n����
//		for (int i = 1; i <= n; i++)
//		{
//			scanf("%d", &heap[i]);
//		}
//	
//		//������
//		heapSort();
//
//		//ѭ�����n����
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
