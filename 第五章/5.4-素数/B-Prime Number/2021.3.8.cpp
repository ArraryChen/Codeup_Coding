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
			for (int j = 2; j <= (int)sqrt(i * 1.0); j++)	 //����һ:����ȡѭ������ j <= i/2 �ᳬʱ
			{												 //������:���øĽ�����, j ֻ��Ƚϵ� sqrt(i) ����
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
