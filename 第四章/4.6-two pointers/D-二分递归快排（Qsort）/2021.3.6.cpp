//ͬ��C:ֻ�������ݵķ�Χ������

#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 100010;

//Partition:�ҵ�����Ԫ�ص�����
int Partition(int A[], int left, int right){

	//temp:Ĭ������ߵ�Ԫ��Ϊ����
	int temp = A[left];
	while ( left < right )
	{
		//�������Ҳ��ҵ�������С��Ԫ��
		while ( left < right && A[right] > temp ) right--;

		//�����ƶ��������λ��
		A[left] = A[right];

		//����������ҵ���������Ԫ��
		while ( left < right && A[left] <= temp ) left++;

		//�����ƶ��������λ��
		A[right] = A[left];
	}

	//����λ�ü�Ϊ���������λ��
	A[left] = temp;

	//����������
	return left;
}

//����
void quickSort(int A[], int left, int right){

	if ( left < right )
	{
		//pos:����Ԫ�ص����
		int pos = Partition(A, left, right);

		//�����Ԫ������
		quickSort(A, left, pos - 1);

		//���Ҳ�Ԫ������
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
