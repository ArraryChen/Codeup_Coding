#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	
	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		//���Խ���
		double sum = n;

		//������ �� ������ Ԫ��֮��
		for (double i = 2; i <= n; i++)
		{
			sum += 1 / i * ( n - i + 1 ) * 2;       // �� ( n - i + 1 ) * 2 �� 1 / i 
		}
		printf("%.2f\n", sum);
	}

	system("pause");
	return 0;
}
