#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	
	//定义三个矩阵
	int A[2][3], B[3][2], C[2][2];

	while ( scanf("%d %d %d", &A[0][0], &A[0][1], &A[0][2]) != EOF )
	{
		//输入A矩阵
		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &A[1][i]);
		}

		//输入B矩阵
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				scanf("%d", &B[i][j]);
			}
		}

		//计算矩阵C
		for (int i = 0; i < 2; i++)			//矩阵C的行
		{
			for (int j = 0; j < 2; j++)		//矩阵C的列
			{
				C[i][j] = 0;
				for (int k = 0; k < 3; k++)	//遍历矩阵A(的列),B(的行))
				{
					C[i][j] += A[i][k] * B[k][j];	//矩阵乘法公式: C(i,j) += A(i,k) * B(k,j)
				}
			}
		}

		//输出矩阵C
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
