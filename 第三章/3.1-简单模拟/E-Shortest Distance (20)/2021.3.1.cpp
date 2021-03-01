////Overtime
//
//#include<cstdio>
//#include<iostream>
//
//using namespace std;
//
//const int maxn = 100001;
//
//int d[maxn] = {0};
//
//void swap(int *a, int *b){
//
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//
//}
//
//
//int main(){
//
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &d[i]);
//	}
//
//	int m;
//	scanf("%d", &m);
//
//	int a, b;
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d %d", &a, &b);
//		if ( a > b ) swap( &a, &b );
//
//		int d1 = 0, d2 = 0;
//		for (int j = a; j < b; j++)
//		{
//			d1 += d[j];
//		}
//		
//		int j = b;
//		while ( j != a )
//		{
//			d2 += d[j];
//
//			j = (j + 1) % n;
//		}
//
//		if ( d1 < d2 ) printf("%d\n", d1);
//		else printf("%d\n", d2);
//	}
//
//	system("pause");
//	return 0;
//}
