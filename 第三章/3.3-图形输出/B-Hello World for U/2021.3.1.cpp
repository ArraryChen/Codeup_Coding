//��Ŀ�ѵ�:���������ļ��� & �м��ַ�(�ո�)�ļ���(Ҫ�����������ʽ��)

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 100;

int main(){

	//str:��������ַ���
	char str[maxn];
	scanf("%s", str);

	//�����ַ����ĳ���
	int length = strlen(str);

	//side:���ߵ��ַ���
	int side = (length + 2) / 3;

	//�м���ַ���
	int mid = length - side * 2;

	//i:��ǰ���������ַ�
	int i = 0;

	//����ǰside - 1�м��пո��Ե��,����ѭ����ѭ�����ǰside-1��
	for (int j = 0; i < side - 1; i++, j++)
	{
		printf("%c", str[j]);
		for (int k = 0; k < mid; k++)
		{
			printf(" ");
		}
		printf("%c\n", str[length-j-1]);
	}
	
	//�ٵ���������һ��
	while ( i <= length - side )
	{
		printf("%c", str[i++]);
	}

	system("pause");
	return 0;
}
