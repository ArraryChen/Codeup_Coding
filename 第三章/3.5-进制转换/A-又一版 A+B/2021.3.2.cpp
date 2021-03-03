#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	//m:进制
	int m;
	while ( scanf("%d", &m) != EOF )
	{
		if ( m == 0 ) break;
		
		//ans:存放m进制数
		vector<int> ans;

		//输入两个整数
		long long num1, num2, sum;
		scanf("%lld %lld", &num1, &num2);

		//求两数之和
		sum = num1 + num2;

		//注意:这种方式需要将sum=0的情况分出来单独讨论
		if ( sum == 0 )
		{
			printf("0\n");
			continue;
		}

		//若sum非零(除基取余法)
		while ( sum )
		{
			int temp = sum % m;	//得到余数作为m进制数的低位
			sum /= m;			//再将商继续进行上述操作,直至为0

			ans.push_back(temp);//从低位到高位存放ans
		}
		//再逆向输出即可
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			printf("%d", ans[i]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
