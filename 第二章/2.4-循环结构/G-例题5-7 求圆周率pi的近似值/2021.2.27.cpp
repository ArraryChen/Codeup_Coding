#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	//PI
	double PI = 0.0;

	//i:��ĸ
	double i = 1.0;

	//count:����
	int count = 1;

	while ( (1.0 / i) >= 1e-6 )
	{
		if ( count == 1 )
		{
			PI += 1.0 / i;

			count = 2;
		}
		else if ( count == 2 )
		{
			PI -= 1.0 / i;

			count = 1;
		}

		i = i + 2.0;
	}

	//һ����Ҫ����, ��Ŀ������ PI / 4
	//������� ���� 4 ���ǽ��
	printf("PI=%10.8f\n", PI * 4);

	system("pause");
	return 0;
}
