//����doubleΪ64λ,����ĿҪ��,ÿ�����ݲ�����100���ַ� >= 64 , ��double������

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

//�������ӷ�,С���������,�����������
struct bign{

	int d1[200];	//��������
	int d2[200];	//С������
	int len1;		//�������ֳ���
	int len2;		//С�����ֳ���

	bign(){         //��ʼ������
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		len1 = len2 = 0;
	}
};

//���ַ�����ʽ���븡����, ����ת����bign���͵ĸ�����
bign change(char str[]){

	bign a;
	int i = 0;
	
	//���ڴ������ӷ�ʱ,�ȼӵ�λ�ٵ���λ,���Դ洢ʱ,�ӵ�λ����λ˳��洢
	//��whileѭ��,�ҵ������������λ������
	while ( str[i] != '.' ) i++;		
	
	//��������
	for (int j = i - 1; j >= 0; j--)
	{
		a.d1[a.len1++] = str[j] - '0';
	}

	//��whileѭ��,�ҵ�С���������λ������
	while ( str[i] != '\0' ) i++;

	//С������
	for (int j = i - 1; str[j] != '.'; j--)
	{
		a.d2[a.len2++] = str[j] - '0';
	}

	//����ת����ĸ�����
	return a;
}

//�������ӷ�
bign add(bign a, bign b){

	//c:���� ( a + b = c )
	bign c;

	//�������ڼ��㸡����ʱ,�ȼ���С������,�ټ�����������
	//������С�����ֵ�λ�����ܴ��ڲ�һ������,�����ȼ�����������,С�����ֳ��ȵĲ�ֵ
	int sub_len = (a.len2 >= b.len2) ? a.len2 - b.len2 : b.len2 - a.len2;

	//a1:С����������
	//b1:С����������
	int a1 = 0, b1 = 0;

	//�ȰѶ����С�����ֵ�λ��,�ȼӵ�������
	if ( a.len2 > b.len2 )
	{
		for (a1 = 0; a1 < sub_len; a1++)
		{
			c.d2[c.len2++] = a.d2[a1];
		}
	}
	else if ( b.len2 > a.len2 )
	{
		for (b1 = 0; b1 < sub_len; b1++)
		{
			c.d2[c.len2++] = b.d2[b1];
		}
	}

	//carry:��λ
	int carry = 0;

	//С������(���մ������ӷ�)����,�����λ,�����λ,ע���λ
	for (; b1 < b.len2 || a1 < a.len2; a1++, b1++)
	{
		int temp = a.d2[a1] + b.d2[b1] + carry;
		c.d2[c.len2++] = temp % 10;
		carry = temp / 10;
	}

	//��������(���մ������ӷ�)����,�����λ,�����λ,ע��С�����������Ľ�λ
	for (int i = 0; i < a.len1 || i < b.len1; i++)
	{
		int temp = a.d1[i] + b.d1[i] + carry;
		c.d1[c.len1++] += temp % 10;
		carry = temp / 10;
	}
	
	//���غ���
	return c;
}

//��ӡ������
void print(bign a){

	//�������������
	for (int i = a.len1 - 1; i >= 0; i--)
	{
		printf("%d", a.d1[i]);
	}

	//����������С���Ƿֿ��洢��,�����������,��Ҫ���С����
	printf(".");

	//����С�������Ǵӵ�λ����λ�����,��λ���ֿ��ܴ�������Ч����
	//����:3.56 + 2.34 = 5.90 ��������㲻�����

	//j:С���������һλ��Чλ������(С�������Ǵӵ�λ����λ�洢��)
	int j = 0;
	while ( a.d2[j] == 0 ) j++;

	//�������������
	for (int i = a.len2 - 1; i >= 0; i--)
	{
		if ( i < j ) break;
		printf("%d", a.d2[i]);
	}
	printf("\n");
}

int main(){

	//n:������
	int n;
	scanf("%d", &n);
	while ( n-- )
	{
		//str1, str2:���ַ�����ʽ���븡����
		char str1[200], str2[200];
		scanf("%s", str1);
		scanf("%s", str2);

		bign a = change(str1);
		bign b = change(str2);
			
		print(add(a, b));
		
		//ÿ���������֮����һ������
		getchar();
	}

	system("pause");
	return 0;
}
