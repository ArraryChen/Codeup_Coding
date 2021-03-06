#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

//ans:保存输入的整数
vector<int> ans;

int func(int n, int w){
	
	if ( w == 40 ) return 1;									//重量达40时,满足题目要求
	else if ( w > 40 ) return 0;								//重量超过40时,不满足题目要求,返回0
	else if ( n == ans.size() ) return 0;						//当已经遍历完所有元素时,重量还不达到40,返回0
	else return func( n + 1, w + ans[n] ) + func( n + 1, w );	//当未遍历完所有元素时,重量还不达到40,根据两种方案选择:选择当前物品 & 不选择当前物品

}

int main(){

	//n:待输入的整数个数
	int n;
	while ( scanf("%d" ,&n) != EOF )
	{
		if ( n == 0 ) break;
		
		//num:临时变量,保存待输入的整数
		int num;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			ans.push_back( num );
		}

		//count:记录了本次的方案数
		int count = func( 0, 0 );

		printf("%d\n", count);

		//清空保存的所有整数
		ans.clear();
	}

	system("pause");
	return 0;
}
