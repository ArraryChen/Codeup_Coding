#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 10010;

int main(){

	//��ת�����ַ���
	char str[maxn];
	scanf("%s", str);

	//length:�ַ�������
	int length = strlen(str);

	//ת��
	for (int i = 0; i < length; i++)
	{
		if ( str[i] >= 'a' && str[i] <= 'z' )
		{
			str[i] = 26 - ( str[i] - 'a' + 1 ) + 'a';
		}
		else if ( str[i] >= 'A' && str[i] <= 'Z' )
		{
			str[i] = 26 - ( str[i] - 'A' + 1 ) + 'A';
		}
	}

	//���ת������ַ���
	printf("%s", str);

	system("pause");
	return 0;
}
