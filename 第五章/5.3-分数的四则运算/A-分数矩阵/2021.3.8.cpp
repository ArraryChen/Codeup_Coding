#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	
	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		//主对角线
		double sum = n;

		//上三角 与 下三角 元素之和
		for (double i = 2; i <= n; i++)
		{
			sum += 1 / i * ( n - i + 1 ) * 2;       // 有 ( n - i + 1 ) * 2 个 1 / i 
		}
		printf("%.2f\n", sum);
	}

	system("pause");
	return 0;
}
