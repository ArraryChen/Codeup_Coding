//����:https://blog.csdn.net/qq_34432960/article/details/88620884

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

struct bign{

	int d[1010];
	int len;

	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

//���ַ����鱣�����ת��Ϊbign
bign change(char str[]){

	bign a;
	a.len = strlen(str);

	for (int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

//��������

//a:bign���͵���
//m:bign�Ľ���
//b:����
//r:����
bign divide(bign a, int m, int b, int &r){

	bign c;
	c.len = a.len;

	r = 0;

	for (int i = a.len - 1; i >= 0; i--)
	{
		r = r * m + a.d[i];

		if ( r >= b )
		{
			c.d[i] = r / b;
			r = r % b;
		}
		else
		{
			c.d[i] = 0;
		}
	}
	//����������������,��λ��0,�����´�������ʱ,����һλ��ʼ����
	//case:170 / 2 = 085
	//�̵ĸ�λ0,���ز�������,�� c.len--
	while ( c.len >= 1 && c.d[c.len - 1] == 0 ) c.len--;

	return c;
}

int main(){
	
	bign x;

	//j:����
	//r:��������
	int j = 0, r = 0;

	//ע�������1000λʮ��������ת��Ϊ������ʱ,λ������Ҫ����1000λ,����Ҫ����Щ
	//str:���������ʮ������
	//bin:����ת����Ķ�������
	//ans:��������ʮ���ƽ��
	char str[1010], ans[2000], bin[3500];

	//�����ת����ʮ������
	while ( scanf("%s", str) != EOF )
	{
		//��ʼ�� j, r
		j = r = 0;

		//���ַ�������ת��Ϊ bign
		x = change(str);

		//ͨ������ȡ�෨,��ʮ����ת��Ϊ��������(ת����Ķ������Ǵӵ�λ����λ˳���ŷŵ�)
		while ( x.len >= 1 )
		{
			x = divide(x, 10, 2, r);
			bin[j++] = r + '0';
		}
		//�ǵ�ĩβ���Ͻ�����
		bin[j] = '\0';

		//����������ת��Ϊ bign (���������λ����������ĵ�λ,����ĸ�λ����������ĸ�λ)
		//change()�������Ǵ������λ����λ˳��ת����,���������ת���Ĳ���
		x = change(bin);
		
		//��ʼ�� j
		j = 0;

		//ͨ������ȡ�෨,��������ת��Ϊʮ������
		while ( x.len >= 1 )
		{
			x = divide(x, 2, 10, r);
			ans[j++] = r + '0';
		}
		//�ǵ�ĩβ���Ͻ�����
		ans[j] = '\0';

		//���ڵ�λ�����ʮ���Ƶĵ�λ,��λ�����ʮ���Ƶĸ�λ
		//�������
		for (int i = j - 1; i >= 0; i--)
		{
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
