////���������Ƚ��鷳
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
//	//add:��Ҫ���ӵ�����
//	int year, month, day, add;
//	while ( m )
//	{
//		int dayOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//		//����������
//		scanf("%d %d %d %d", &year, &month, &day, &add);
//		while ( add )
//		{
//			//ע��:�����ڽ�����������ʱ,��ݻ�任,����ζ��ÿ���2�·ݵ������Ǳ仯��
//			//������ÿ��ѭ��ʱ��Ҫ�жϸ��������껹��ƽ��
//
//			//�жϸ����Ƿ�������
//			bool result = judgeYear(year);
//			//���������,���¼�һ��
//			if ( result == true ) dayOfMonth[2] = 29;
//			else dayOfMonth[2] = 28;
//
//			//temp:���滹���������ܵ���ĩ
//			int temp = dayOfMonth[month] - day;
//
//			//���ӵ�����û�ܳ�����ĩ
//			if ( add <= temp )
//			{
//				day += add;
//				add = 0;
//			}
//			//���ӵ�������������ĩ,ֱ������Ϊ�¸��µ�һ��
//			else
//			{
//				add = add - temp - 1;	//������������
//				month++;				//�·�������һ
//				day = 1;				
//
//				//���·�����������12����
//				if ( month > 12 )
//				{
//					year++;				//��ݼ�һ
//					month = 1;			
//				}
//			}
//		}//add = 0 ����
//
//		printf("%04d-%02d-%02d\n", year, month, day);
//		m--;
//	}
//
//	system("pause");
//	return 0;
//}
