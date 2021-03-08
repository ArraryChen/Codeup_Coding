#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

//重点一
//求最大公因数 - 辗转相除法 gcd(a, b) = gcd(b, a % b)
int gcd(int a, int b){

	if ( b == 0 ) return a;
	else return gcd(b, a % b);

}

int main(){

	//m:测试用例数量
	int m;
	scanf("%d", &m);

	while ( m-- )
	{
		//n:输入正整数数量
		int n;
		scanf("%d", &n);

		//重点二
		//d:最小公倍数 - [a,b]:  a * b / gcd(a, b);
		//x:临时变量,保存输入的正整数
		int x, d = 1;

		//思路:将求多个数的最小公倍数,转换为先求两个数的最小公倍数,再求这个最小公倍数与下个输入正整数的最小公倍数,直至所以正整数遍历完毕
		for (int i = 0; i < n; i++)
		{
			//当 i = 0, d = x
			scanf("%d", &x);
			d = d / gcd(d, x) * x;
		}

		printf("%d\n", d);
	}
	
	system("pause");
	return 0;
}
