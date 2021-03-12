#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<iostream>

using namespace std;

struct node{

	double num;			//数字
	char op;			//运算符
	bool flag;			//flag = true , node保存数字
						//flag = false , node保存运算符
};

string str;				//输入表达式
stack<node> s;			//保存运算符
queue<node> q;			//保存数字
map<char, int> op;		//保存运算符 & 优先级

void change(){          //将中缀表达式转换为后缀表达式(用队列保存)

	node temp;			//临时变量,保存数字或运算符

	for (int i = 0; i < str.length(); )
	{
		//遇到数字
		if ( str[i] >= '0' && str[i] <= '9' )
		{
			temp.flag = true;				//标记为数字
			temp.num = str[i++] - '0';		//存入当前遇到的数字

			while ( i < str.length() && str[i] >= '0' && str[i] <= '9' )
				temp.num = temp.num * 10 + (str[i++] - '0');

			q.push(temp);
		}
		//遇到运算符
		else
		{
			temp.flag = false;				//标记为运算法
			while ( !s.empty() && op[str[i]] <= op[s.top().op] )	//判断当前运算符与栈顶运算符优先级
			{
				q.push(s.top());
				s.pop();
			}

			temp.op = str[i++];
			s.push(temp);
		}
	}

	//将剩余的运算符存入队列中
	while ( !s.empty() )
	{
		q.push(s.top());
		s.pop();
	}
}

//计算结果
double cal(){

	double temp1, temp2;	//参与运算的两个数
	node cur, temp;

	while ( !q.empty() )
	{
		cur = q.front();
		q.pop();

		//遇到数字,压入堆栈
		if ( cur.flag == true )
		{
			s.push(cur);
		}
		//遇到运算符,弹出栈顶的两个数
		else
		{
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();

			temp.flag = true;
			if ( cur.op == '+' )
			{
				temp.num = temp1 + temp2;
			}
			else if ( cur.op == '-' )
			{
				temp.num = temp1 - temp2;
			}
			else if ( cur.op == '*' )
			{
				temp.num = temp1 * temp2;
			}
			else if ( cur.op == '/' )
			{
				temp.num = temp1 / temp2;
			}

			s.push(temp);
		}
	}
	return s.top().num;
}

int main(){

	//设置运算符的优先级
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;

	//输入表达式,若输入0或者空,则结束输入
	while ( getline(cin, str) && str != "0"  && str.length() != 0 )
	{
		//清空表达式中的空格
		for ( string::iterator it = str.end() - 1; it != str.begin(); it-- )
			if ( *it == ' ' )
				str.erase(it);

		//清空上一次保存的结果
		while ( !s.empty() ) s.pop();

		//将中缀表达式转换为后缀表达式
		change();

		//输出结果
		printf("%.2f\n", cal());
	}
	system("pause");
	return 0;
}
