//那天数逐渐叠加的思路比较容易
#include<cstdio>
#include<iostream>

using namespace std;

bool judgeYear(int year){

	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

}

int main(){

	int m;
	scanf("%d", &m);

	while ( m )
	{
		int year, month, day, add;
		scanf("%d %d %d %d", &year, &month, &day, &add);

		for (int i = 0; i < add; i++)
		{
			int dayOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			bool result = judgeYear(year);

			if ( result == true ) dayOfMonth[2] = 29;
			else dayOfMonth[2] = 28;

			day++;
			if ( day > dayOfMonth[month] )
			{
				month++;
				day = 1;
			}
			if ( month > 12 )
			{
				year++;
				month = 1;
			}
		}//for end
		//add = 0;
		printf("%04d-%02d-%02d\n", year, month, day);
		m--;
	}

	system("pause");
	return 0;
}
