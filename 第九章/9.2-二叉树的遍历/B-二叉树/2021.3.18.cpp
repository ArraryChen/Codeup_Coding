#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int m, n;
	while ( scanf("%d %d", &m, &n) != EOF && m && n )
	{
		int left, right, cnt;

		cnt = 0;
		left = right = m;

		while ( left <= n )
		{
			cnt += right - left + 1;

			left = left * 2;			//left: �������ĵ�һ������
			right = right * 2 + 1;		//right: �����������һ������
			if ( right > n ) right = n;
		}
		
		printf("%d\n", cnt);
	}

	system("pause");
	return 0;
}
