//这道题OJ评判测试样例出错,答案正确会出现运行错误20%
//可以发现解决的人数为0

#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

const int maxn = 100010;

void merge(int A[], int L1, int R1, int L2, int R2){

	int i = L1, j = L2;

	int temp[maxn], index = 0;

	while ( i <= R1 && j <= R2 )
	{
		if ( A[i] <= A[j] ) temp[index++] = A[i++];
		else temp[index++] = A[j++];
	}
	while ( i <= R1 ) temp[index++] = A[i++];
	while ( j <= R2 ) temp[index++] = A[j++];
	for (i = 0; i < index; i++)
	{
		A[L1 + i] = temp[i];
	}
}

void mergeSort(int A[], int left, int right){

	if ( left < right )
	{
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid+1, right);
		merge(A, left, mid, mid+1, right);
	}
}

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n < 1 || n > 100000 ) break;

		int A[maxn];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
		}

		mergeSort(A, 0, n-1);

		for (int i = 0; i < n; i++)
		{
			printf("%d", A[i]);
			if ( i < n - 1 ) printf(" ");
			else printf("\n");
		}
	}

	system("pause");
	return 0;
}
