#include<cstdio>
#include<stack>
#include<string>
#include<iostream>

using namespace std;

int main(){

	//n:输入的字符串个数
	int n;
	scanf("%d", &n);
	getchar();

	while ( n-- )
	{
		//result = true 匹配
		//result = false 不匹配
		bool result = true;

		//ans:保存左括号
		stack<char> ans;

		//str:保存输入的字符串
		string str;
		getline(cin, str);

		//循环判断
		for (int i = 0; i < str.length(); i++)
		{
			//若为左括号,压入堆栈
			if ( str[i] == '(' || str[i] == '[' || str[i] == '{' )
			{
				ans.push(str[i]);
			}
			//若为右括号,依次判断
			else if ( str[i] == ')' || str[i] == ']' || str[i] == '}' )
			{
				//若堆栈为空,说明没有左括号可以与之匹配
				if ( ans.empty() )
				{
					result = false;
					break;
				}

				char ch = ans.top();

				//若堆栈不为空,则判断栈顶括号是否与之匹配
				if ( str[i] == ')' )
				{
					if ( ch == '(' )
						ans.pop();
					else if ( ch != '(' )
					{
						result = false;
						break;
					}
				}
				else if ( str[i] == ']' )
				{
					if ( ch == '[' )
						ans.pop();
					else if ( ch != '[' )
					{
						result = false;
						break;
					}
				}
				else if ( str[i] == '}' )
				{
					if ( ch == '{' )
						ans.pop();
					else if ( ch != '{' )
					{
						result = false;
						break;
					}
				}
			}
		}

		//判断 result 是否为 true , 并且堆栈为空 
		if ( result == true && ans.empty() ) printf("yes\n");
		else printf("no\n");
	}

	system("pause");
	return 0;
}
