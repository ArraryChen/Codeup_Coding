#include<cstdio>
#include<iostream>

using namespace std;

bool judgeNum(int n){

	int number = n * 9;

	int pos1 = n / 1000;
	int pos2 = n / 100 % 10;
	int pos3 = n % 100 / 10;
	int pos4 = n % 100 % 10;

	int number2 = pos4 * 1000 + pos3 * 100 + pos2 * 10 + pos1 * 1;

	if ( number2 == number ) return true;
	else return false;

}

//ps:������ֲ�����λ���Ļ�,���Բ��õ�˼·����,���ΰ��������9����ÿһλ,���䱾���ÿһλȡ��,���Ӧ�Ƚϼ���

int main(){

	for (int i = 1000; i < 10000; i++)
	{
		if ( judgeNum(i) ) printf("%d\n", i);
	}

	system("pause");
	return 0;
}
