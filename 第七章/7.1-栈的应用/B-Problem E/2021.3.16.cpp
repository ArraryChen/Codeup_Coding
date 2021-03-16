#include<cstdio>
#include<string>
#include<stack>
#include<iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);
	getchar();

	while ( n-- )
	{
		string str;
		stack<char> s;

		bool result = true;
		getline(cin, str);

		for (int i = 0; i < str.length(); i++)
		{
			if ( str[i] == '(' || str[i] == '[' || str[i] == '{' )
			{
				s.push(str[i]);
			}
			else if ( str[i] == ')' || str[i] == ']' || str[i] == '}' )
			{
				if ( s.empty() )
				{
					result = false;
					break;
				}

				else if ( str[i] == ')' && s.top() != '(' )
				{
					result = false;
					break;
				}
				else if ( str[i] == ']' && s.top() != '[' )
				{
					result = false;
					break;
				}
				else if ( str[i] == '}' && s.top() != '{' )
				{
					result = false;
					break;
				}
				else
				{
					s.pop();
				}
			}
		}

		if ( result && s.empty() ) printf("yes\n");
		else printf("no\n");
	}

	system("pause");
	return 0;
}
