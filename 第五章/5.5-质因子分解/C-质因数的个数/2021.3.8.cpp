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
////初始化素数表
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
//		//count:统计n的质因数个数
//		int count = 0;
//		
//		//遍历素数表
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
//		// 存在大于 sqrt(1.0 * n) 的因子
//		if ( n != 1 ) count++;
//
//		printf("%d\n", count);
//	}
//
//	system("pause");
//	return 0;
//}
