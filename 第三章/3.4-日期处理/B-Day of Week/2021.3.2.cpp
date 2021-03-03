//����ת��:����˼·���ǽ�������ͳһת��Ϊ������λ,�������1����

#include<cstdio>
#include<iostream>

using namespace std;

const int dayOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//�ж�ĳһ���Ƿ�Ϊ����
bool judgeYear(int year){

	if ( year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ) return true;
	else return false;

}


int main(){

	int num1, num2;
	while ( scanf("%d %d", &num1, &num2) != EOF )
	{
		int year1 = num1 / 10000;
		int year2 = num2 / 10000;

		int month1 = num1 / 100 % 100;
		int month2 = num2 / 100 % 100;

		int day1 = num1 % 100;
		int day2 = num2 % 100;

		//����˼·���ǽ�������ͳһ��дΪ��Ϊ����
		int total1 = 0, total2 = 0, ans;

		//��ת����
		for (int i = 1; i < year1; i++)
		{
			if ( judgeYear(i) == true ) total1 += 366;
			else total1 += 365;
		}
		for (int i = 1; i < year2; i++)
		{
			if ( judgeYear(i) == true ) total2 += 366;
			else total2 += 365;
		}

		//��ת����
		for (int i = 1; i < month1; i++)
		{
			total1 += dayOfMonth[i];
		}
		//�������������,�����·ݳ�����2��,��Ҫ��1��,��Ϊ����2����29��
		if ( judgeYear(year1) == true && month1 > 2 ) total1++;

		for (int i = 1; i < month2; i++)
		{
			total2 += dayOfMonth[i];
		}
		if ( judgeYear(year2) == true && month2 > 2 ) total2++;
		
		//��ת����
		total1 += day1;
		total2 += day2;

		//��ֵ�Ǹ�������
		if ( total1 < total2 )
		{
			int temp = total1;
			total1 = total2;
			total2 = temp;
		}
		ans = total1 - total2 + 1;

		printf("%d\n", ans);
	}

	system("pause");
	return 0;
}
