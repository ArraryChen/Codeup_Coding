#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<iostream>

using namespace std;

struct node{

	double num;			//����
	char op;			//�����
	bool flag;			//flag = true , node��������
						//flag = false , node���������
};

string str;				//������ʽ
stack<node> s;			//���������
queue<node> q;			//��������
map<char, int> op;		//��������� & ���ȼ�

void change(){          //����׺���ʽת��Ϊ��׺���ʽ(�ö��б���)

	node temp;			//��ʱ����,�������ֻ������

	for (int i = 0; i < str.length(); )
	{
		//��������
		if ( str[i] >= '0' && str[i] <= '9' )
		{
			temp.flag = true;				//���Ϊ����
			temp.num = str[i++] - '0';		//���뵱ǰ����������

			while ( i < str.length() && str[i] >= '0' && str[i] <= '9' )
				temp.num = temp.num * 10 + (str[i++] - '0');

			q.push(temp);
		}
		//���������
		else
		{
			temp.flag = false;				//���Ϊ���㷨
			while ( !s.empty() && op[str[i]] <= op[s.top().op] )	//�жϵ�ǰ�������ջ����������ȼ�
			{
				q.push(s.top());
				s.pop();
			}

			temp.op = str[i++];
			s.push(temp);
		}
	}

	//��ʣ�����������������
	while ( !s.empty() )
	{
		q.push(s.top());
		s.pop();
	}
}

//������
double cal(){

	double temp1, temp2;	//���������������
	node cur, temp;

	while ( !q.empty() )
	{
		cur = q.front();
		q.pop();

		//��������,ѹ���ջ
		if ( cur.flag == true )
		{
			s.push(cur);
		}
		//���������,����ջ����������
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

	//��������������ȼ�
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;

	//������ʽ,������0���߿�,���������
	while ( getline(cin, str) && str != "0"  && str.length() != 0 )
	{
		//��ձ��ʽ�еĿո�
		for ( string::iterator it = str.end() - 1; it != str.begin(); it-- )
			if ( *it == ' ' )
				str.erase(it);

		//�����һ�α���Ľ��
		while ( !s.empty() ) s.pop();

		//����׺���ʽת��Ϊ��׺���ʽ
		change();

		//������
		printf("%.2f\n", cal());
	}
	system("pause");
	return 0;
}
