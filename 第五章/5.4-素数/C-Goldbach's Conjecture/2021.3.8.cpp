////速度较慢,更好的方式是先保存一个素数表,再依次遍历判断,详见 a new solution.cpp

//#include<cstdio>
//#include<cmath>
//#include<iostream>
//
//using namespace std;
//
//bool judgePrime(int num){
//
//	for (int i = 2; i <= (int)sqrt( num * 1.0 ); i++)
//	{
//		if ( num % i == 0 )
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main(){
//
//	int n;
//	while ( scanf("%d", &n) != EOF && n )
//	{
//		int count = 0;
//
//		for (int i = 2; i < n; i++)
//		{
//			for (int j = i; j <= n - i; j++)
//			{
//				if ( i + j == n )
//				{
//					if ( judgePrime(i) && judgePrime(j) )
//					{
//						count++;
//					}
//				}
//			}
//		}
//		printf("%d\n", count);
//	}
//
//	system("pause");
//	return 0;
//}
