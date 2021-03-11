#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

struct bign{

	int d[10010];
	int len;

	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign mul(bign a, int b){

	bign c;

	int carry = 0;
	for (int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while ( carry != 0 )
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

void print(bign a){

	for (int i = a.len - 1; i >= 0; i--)
	{
		printf("%d", a.d[i]);
	}
	printf("\n");
}

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		//���������a
		bign a;

		//��ʼ�� a.d[0] = 1 ԭ����
		//�� n = 0, n = 1 ʱ�������Ҫ��������
		a.d[0] = 1;
		a.len = 1;

		for (int i = 2; i <= n; i++)
		{
			a = mul(a, i);
		}
		print(a);
	}

	system("pause");
	return 0;
}