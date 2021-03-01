#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	//PI
	double PI = 0.0;

	//i:分母
	double i = 1.0;

	//count:计数
	int count = 1;

	while ( (1.0 / i) >= 1e-6 )
	{
		if ( count == 1 )
		{
			PI += 1.0 / i;

			count = 2;
		}
		else if ( count == 2 )
		{
			PI -= 1.0 / i;

			count = 1;
		}

		i = i + 2.0;
	}

	//一定不要忘了, 题目给定是 PI / 4
	//所以输出 乘上 4 才是结果
	printf("PI=%10.8f\n", PI * 4);

	system("pause");
	return 0;
}
