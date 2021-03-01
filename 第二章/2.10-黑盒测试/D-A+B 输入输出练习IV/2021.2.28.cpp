#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF , n )
	{
		int sum = 0, num;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
	}

	system("pause");
	return 0;
}
