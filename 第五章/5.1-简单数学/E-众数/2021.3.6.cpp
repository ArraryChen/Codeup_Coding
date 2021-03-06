#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int num;

	//题目说明了,测试数据有多组,所以必须先输入第一个数字,再输入剩余的19个数字
	while ( scanf("%d", &num) != EOF )
	{
		int count[11] = { 0 };
		count[num]++;

		//输入剩余的19个数字
		for (int i = 1; i < 20; i++)
		{
			scanf("%d", &num);

			count[num]++;
		}
	
		//max:众数
		//max_count:众数出现的次数
		int max = 1, max_count = -1;

		//循环找到众数
		for (int i = 1; i < 11; i++)
		{
			if ( count[i] > max_count )
			{
				max = i;
				max_count = count[i];
			}
		}
		printf("%d\n", max);
	}

	system("pause");
	return 0;
}
