//注意理解题目的最低位的含义

#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	//n:输入的正整数
	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n < 2 || n >= 100 ) break;

		//num_square:输入的正整数的平方
		int num_square = n * n;

		//nums:保存输入的正整数的每一位
		vector<int> nums;

		//遍历取出输入正整数n的每一位
		while ( num_square )
		{
			int pos = num_square % 10;	//取出最低位
			nums.push_back(pos);		//将最低位放入nums

			num_square /= 10;			//除去最低位
		}

		//w:每一位的权值(初始个位,权值为1)
		int w = 1;

		//遍历nums的每一位(除去最高位)
		bool result = false;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			num_square += nums[i] * w;

			w *= 10;

			//从最低位开始遍历的过程中,发现有数字与原先输入的数字相同时,退出循环
			if ( num_square == n )
			{
				result = true;
				break;
			}
		}
		if ( result ) printf("Yes!\n");
		else printf("No!\n");
	}

	system("pause");
	return 0;
}
