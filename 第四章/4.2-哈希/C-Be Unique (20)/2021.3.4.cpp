#include<cstdio>
#include<vector>
#include<map>
#include<iostream>

using namespace std;

int main(){

	//n:保存输入的整数个数
	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 ) break;

		//ans:保存输入的整数(打赌的编号)及其出现的次数
		map<int, int> ans;

		//nums:保存输入的整数
		vector<int> nums;

		//bet_num:临时变量,保存输入的整数(打赌的编号)
		int bet_num = 0;

		//循环输入
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &bet_num);
			nums.push_back(bet_num);

			//判断map中是否能找到该变量,若能,出现次数加一,否则初始化次数为1
			if ( ans.find(bet_num) != ans.end() ) ans[bet_num]++;
			else ans[bet_num] = 1;
		}

		//result:保存是否有胜负
		bool result = false;

		//根据输入数字的顺序来遍历
		for (int i = 0; i < nums.size(); i++)
		{
			//判断当前输入在map中出现的次数是否为一,若是,则输出该数字(打赌的编号)
			if ( ans[nums[i]] == 1 )
			{
				printf("%d\n", nums[i]);
				result = true;
				break;
			}
		}
		//若判断不出胜负,输出None
		if ( result == false ) printf("None\n");
	}

	system("pause");
	return 0;
}
