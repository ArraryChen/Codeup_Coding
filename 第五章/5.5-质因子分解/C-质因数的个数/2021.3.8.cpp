//#include<cstdio>
//#include<cmath>
//#include<iostream>
//
//using namespace std;
//
//const int maxn = 100010;
//
//int prime[maxn], num = 0;
//bool p[maxn] = { false };
//
////��ʼ��������
//void findPrime(){
//
//	for (int i = 2; i < maxn; i++)
//	{
//		if ( p[i] == false )
//		{
//			prime[num++] = i;
//			for (int j = i + i; j < maxn; j += i)
//			{
//				p[j] = true;
//			}
//		}
//	}
//}
//
//int main(){
//
//	findPrime();
//
//	int n;
//	while ( scanf("%d", &n) != EOF && n > 1 ) // && n < 1e9 
//	{
//		//count:ͳ��n������������
//		int count = 0;
//		
//		//����������
//		for (int i = 0; i < num && prime[i] <= (int)sqrt(1.0 * n); i++)
//		{
//			if ( n % prime[i] == 0 )
//			{
//				while ( n % prime[i] == 0 )
//				{
//					count++;
//					n /= prime[i];
//				}
//			}
//			if ( n == 1 ) break;
//		}
//		// ���ڴ��� sqrt(1.0 * n) ������
//		if ( n != 1 ) count++;
//
//		printf("%d\n", count);
//	}
//
//	system("pause");
//	return 0;
//}
