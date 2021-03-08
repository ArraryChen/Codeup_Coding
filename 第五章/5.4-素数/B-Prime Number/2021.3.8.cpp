#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int main(){

	int k;
	while ( scanf("%d", &k) != EOF && k )
	{
		int count = 0, i = 1;

		while ( count != k )
		{
			i++;
			bool result = true;
			for (int j = 2; j <= (int)sqrt(i * 1.0); j++)	 //方法一:若采取循环调节 j <= i/2 会超时
			{												 //方法二:采用改进方法, j 只需比较到 sqrt(i) 即可
				if ( i % j == 0 )
				{
					result = false;
					break;
				}
			}
			if ( result ) count++;
		}
		printf("%d\n", i);
	}

	system("pause");
	return 0;
}
