#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

//�ص�һ
//��������� - շת����� gcd(a, b) = gcd(b, a % b)
int gcd(int a, int b){

	if ( b == 0 ) return a;
	else return gcd(b, a % b);

}

int main(){

	//m:������������
	int m;
	scanf("%d", &m);

	while ( m-- )
	{
		//n:��������������
		int n;
		scanf("%d", &n);

		//�ص��
		//d:��С������ - [a,b]:  a * b / gcd(a, b);
		//x:��ʱ����,���������������
		int x, d = 1;

		//˼·:������������С������,ת��Ϊ��������������С������,���������С���������¸���������������С������,ֱ�������������������
		for (int i = 0; i < n; i++)
		{
			//�� i = 0, d = x
			scanf("%d", &x);
			d = d / gcd(d, x) * x;
		}

		printf("%d\n", d);
	}
	
	system("pause");
	return 0;
}
