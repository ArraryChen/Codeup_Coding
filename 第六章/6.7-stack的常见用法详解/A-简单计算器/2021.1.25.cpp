////总体思路：将中缀表达式转化为后缀表达式，让后依次遍历后缀表达式计算
////头文件
//#include<cstdio>
//#include<iostream>
//#include<string>
//#include<stack>
//#include<queue>
//#include<map>
//
//using namespace std;
//
////结构体
//struct node{	//保存数字或运算符
//	double num;	//保存数字
//	char op;	//保存运算符
//	bool flag;	//flag = true:数字
//				//flag = false:运算符
//};
//
////全局变量
//string str;		//str:保存输入的表达式
//stack<node> s;	//s:保存运算符
//queue<node> q;	//q:保存数字
//map<char,int> op;//op:保存运算符的优先级
//
//
////函数
//void Change(){
//	//将中缀表达式转化为后缀表达式
//	double num;	//num:数字
//	node temp;	
//	for (int i = 0; i < str.length(); )
//	{
//		if (str[i] >='0' && str[i] <='9')//遇到的是数字
//		{
//			temp.flag = true;
//			temp.num = str[i++] - '0';
//			while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
//				temp.num = temp.num * 10 + (str[i] - '0');
//				i++;
//			}
//			q.push(temp);
//		}else//遇到的是操作符
//		{
//			temp.flag = false;
//			while(!s.empty() && op[str[i]] <= op[s.top().op]) {//比较当前遍历到的运算符和栈顶运算符的优先级
//				q.push(s.top());
//				s.pop();
//			}
//			temp.op = str[i];
//			s.push(temp);
//			i++;
//		}
//	}
//	while(!s.empty()){//遍历结束，但是运算符栈中不为空，则将运算符压入队列中
//		q.push(s.top());
//		s.pop();
//	}
//}
//
//double Cal() {//此时栈中保存运算数
//	double temp1,temp2;
//	node cur, temp;
//	while(!q.empty())
//	{
//		cur = q.front();
//		q.pop();
//		if (cur.flag == true)//遇到了数字
//		{
//			s.push(cur);
//		}else
//		{//遇到了运算符
//			temp2 = s.top().num;//取两个操作数
//			s.pop();
//			temp1 = s.top().num;
//			s.pop();
//
//			temp.flag = true;
//			if (cur.op == '+')
//			{
//				temp.num = temp1 + temp2;
//			}else if (cur.op == '-')
//			{
//				temp.num = temp1 - temp2;
//			}else if (cur.op == '*')
//			{
//				temp.num = temp1 * temp2;
//			}else
//			{
//				temp.num = temp1 / temp2;
//			}
//			s.push(temp);//将计算结果压入栈中
//		}
//	}
//	return s.top().num;//最后栈只有一个元素就是结果
//}
//
////程序入口
//int main(){
//
//	op['+'] = op['-'] = 1;
//	op['*'] = op['/'] = 2;
//
//	while(getline(cin,str),str!="0"){
//		if(str=="^Z" || str.length()==0) break;
//
//		for(string::iterator it=str.end()-1; it!=str.begin(); it--){
//			if(*it==' ') str.erase(it);
//		}
//		while(!s.empty()) s.pop();
//		Change();
//		printf("%.2f\n",Cal());
//	}
//
//	system("pause");
//	return 0;
//}