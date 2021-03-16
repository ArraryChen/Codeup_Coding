#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<map>

using namespace std;

struct node{

	char op;
	double num;
	bool flag;

};

string str;
stack<node> s;
queue<node> q;
map<char, int> op;

void change(){

	node temp;

	for ( int i = 0; i < str.length(); )
	{
		if ( str[i] >= '0' && str[i] <= '9' )
		{
			temp.flag = true;
			temp.num = str[i++] - '0';

			while ( i < str.length() && str[i] >= '0' && str[i] <= '9' )
				temp.num = temp.num * 10 + (str[i++] - '0');

			q.push(temp);
		}
		else
		{
			temp.flag = false;
			while ( !s.empty() && op[str[i]] <= op[s.top().op] )
			{
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i++];
			s.push(temp);
		}
	}

	while ( !s.empty() )
	{
		q.push(s.top());
		s.pop();
	}
}

double cal(){

	double temp1, temp2;
	node cur, temp;

	while ( !q.empty() )
	{
		cur = q.front();
		q.pop();

		if ( cur.flag )
		{
			s.push(cur);
		}
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

	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;

	while ( getline(cin, str) && str.length() != 0 && str != "0" )
	{
		for ( string::iterator it = str.end() - 1; it != str.begin(); it-- )
			if ( *it == ' ' )
				str.erase(it);

		while ( !s.empty() ) s.pop();

		change();

		printf("%.2f\n", cal());

	}

	system("pause");
	return 0;
}
