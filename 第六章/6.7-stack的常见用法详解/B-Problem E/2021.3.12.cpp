#include<cstdio>
#include<stack>
#include<string>
#include<iostream>

using namespace std;

int main(){

	//n:������ַ�������
	int n;
	scanf("%d", &n);
	getchar();

	while ( n-- )
	{
		//result = true ƥ��
		//result = false ��ƥ��
		bool result = true;

		//ans:����������
		stack<char> ans;

		//str:����������ַ���
		string str;
		getline(cin, str);

		//ѭ���ж�
		for (int i = 0; i < str.length(); i++)
		{
			//��Ϊ������,ѹ���ջ
			if ( str[i] == '(' || str[i] == '[' || str[i] == '{' )
			{
				ans.push(str[i]);
			}
			//��Ϊ������,�����ж�
			else if ( str[i] == ')' || str[i] == ']' || str[i] == '}' )
			{
				//����ջΪ��,˵��û�������ſ�����֮ƥ��
				if ( ans.empty() )
				{
					result = false;
					break;
				}

				char ch = ans.top();

				//����ջ��Ϊ��,���ж�ջ�������Ƿ���֮ƥ��
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

		//�ж� result �Ƿ�Ϊ true , ���Ҷ�ջΪ�� 
		if ( result == true && ans.empty() ) printf("yes\n");
		else printf("no\n");
	}

	system("pause");
	return 0;
}
