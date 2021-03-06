//同题C:只不过数据的范围扩大了

#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 100010;

//Partition:找到枢轴元素的坐标
int Partition(int A[], int left, int right){

	//temp:默认最左边的元素为枢轴
	int temp = A[left];
	while ( left < right )
	{
		//在枢轴右侧找到比枢轴小的元素
		while ( left < right && A[right] > temp ) right--;

		//令其移动到枢轴的位置
		A[left] = A[right];

		//在枢轴左侧找到比枢轴大的元素
		while ( left < right && A[left] <= temp ) left++;

		//令其移动到枢轴的位置
		A[right] = A[left];
	}

	//最后的位置即为枢轴的最终位置
	A[left] = temp;

	//返回其索引
	return left;
}

//快排
void quickSort(int A[], int left, int right){

	if ( left < right )
	{
		//pos:枢轴元素的左边
		int pos = Partition(A, left, right);

		//对左侧元素排序
		quickSort(A, left, pos - 1);

		//对右侧元素排序
		quickSort(A, pos + 1, right);
	}
}


int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n < 1 && n > 100000 ) break;

		int A[maxn];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
		}
		
		quickSort(A, 0, n-1);
		
		for (int i = 0; i < n; i++)
		{
			printf("%d\n", A[i]);
		}
	}
	system("pause");
	return 0;
}
