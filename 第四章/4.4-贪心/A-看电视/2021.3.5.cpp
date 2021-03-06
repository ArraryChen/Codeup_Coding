#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

struct Time{

	int s;
	int e;

}time1[30];

bool cmp(Time t1, Time t2){

	return t1.e < t2.e;

}

int main(){

	int n;
	while ( scanf("%d", &n) != EOF, n )
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &time1[i].s, &time1[i].e);
		}

		sort(time1, time1 + n, cmp);

		int time_temp = time1[0].e;

		int count = 1;
		for (int i = 1; i < n; i++)
		{
			if ( time_temp <= time1[i].s )
			{
				count++;
				time_temp = time1[i].e;
			}
		}
		printf("%d\n", count);
	}

	system("pause");
	return 0;
}
