#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	
	//������������
	int A[2][3], B[3][2], C[2][2];

	while ( scanf("%d %d %d", &A[0][0], &A[0][1], &A[0][2]) != EOF )
	{
		//����A����
		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &A[1][i]);
		}

		//����B����
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				scanf("%d", &B[i][j]);
			}
		}

		//�������C
		for (int i = 0; i < 2; i++)			//����C����
		{
			for (int j = 0; j < 2; j++)		//����C����
			{
				C[i][j] = 0;
				for (int k = 0; k < 3; k++)	//��������A(����),B(����))
				{
					C[i][j] += A[i][k] * B[k][j];	//����˷���ʽ: C(i,j) += A(i,k) * B(k,j)
				}
			}
		}

		//�������C
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("%d", C[i][j]);
				if ( j < 1 ) printf(" ");
				else printf("\n");
			}
		}
	}//while end

	system("pause");
	return 0;
}
