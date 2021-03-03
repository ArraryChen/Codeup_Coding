#include<cstdio>
#include<iostream>

using namespace std;

const int dayOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){

	int m;
	scanf("%d", &m);
	
	int year, month, day;
	while ( m )
	{
		scanf("%d %d %d", &year, &month, &day);

		if ( day + 1 <= dayOfMonth[month] )
		{
			printf("%04d-%02d-%02d\n", year, month, day+1);
		}
		else
		{
			printf("%04d-%02d-01\n", year, month+1);
		}

		m--;
	}

	system("pause");
	return 0;
}
