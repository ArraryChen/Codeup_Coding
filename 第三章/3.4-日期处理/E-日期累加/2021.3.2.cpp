////这种做法比较麻烦
//
//#include<cstdio>
//#include<iostream>
//
//using namespace std;
//
//bool judgeYear(int year){
//
//	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
//
//}
//
//int main(){
//
//	int m;
//	scanf("%d", &m);
//
//	//add:需要增加的天数
//	int year, month, day, add;
//	while ( m )
//	{
//		int dayOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//		//输入年月日
//		scanf("%d %d %d %d", &year, &month, &day, &add);
//		while ( add )
//		{
//			//注意:由于在进行日期增加时,年份会变换,这意味着每年的2月份的天数是变化的
//			//所以在每次循环时候都要判断该月是闰年还是平年
//
//			//判断该年是否是闰年
//			bool result = judgeYear(year);
//			//如果是闰年,二月加一天
//			if ( result == true ) dayOfMonth[2] = 29;
//			else dayOfMonth[2] = 28;
//
//			//temp:保存还需多少天才能到月末
//			int temp = dayOfMonth[month] - day;
//
//			//增加的天数没能超过月末
//			if ( add <= temp )
//			{
//				day += add;
//				add = 0;
//			}
//			//增加的天数超过了月末,直接令其为下个月的一号
//			else
//			{
//				add = add - temp - 1;	//增加天数减少
//				month++;				//月份天数加一
//				day = 1;				
//
//				//若月份增加至大于12个月
//				if ( month > 12 )
//				{
//					year++;				//年份加一
//					month = 1;			
//				}
//			}
//		}//add = 0 结束
//
//		printf("%04d-%02d-%02d\n", year, month, day);
//		m--;
//	}
//
//	system("pause");
//	return 0;
//}
