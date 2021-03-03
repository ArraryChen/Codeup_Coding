#include<cstdio>
#include<iostream>

using namespace std;

bool judgeYear(int year){

	if ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ) return true;
	else return false;

}

int main(){

	int year, day;
	while ( scanf("%d %d", &year, &day) != EOF )
	{
		int dayOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		//判断是否为闰年
		bool judge = judgeYear(year);
		//若是闰年,二月加一天
		if ( judge == true ) dayOfMonth[2]++;

		//遍历得到月和日
		int month = 1;
		while ( day > dayOfMonth[month] )
		{
			day -= dayOfMonth[month];

			month++;
		}
		printf("%04d-%02d-%02d\n", year, month, day);
	}

	system("pause");
	return 0;
}
