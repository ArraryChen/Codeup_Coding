#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

void conversion(char str[], vector<int> &ans){

	//length:���ַ�����ʽ��Ŵ�ת����ʮ������
	int length = strlen(str);

	//k:�����ÿһλȡ��ʱ������(��һλ�ڼ���ʱʹ�õ�)
	//����������Ϊ������ʱ,��λ��ʣ������,��λ��Ҫ����һ�γ���ʱʹ��
	int k;

	//ѭ��
	for (int i = 0; i < length; )
	{
		k = 0;

		//ѭ����һ�γ���(��λ����)
		for (int j = 0; j < length; j++)
		{
			int t = (k * 10 + str[j] - '0') % 2;		//t:��λ��,ȡ�����,�õ���λ�õ�����,������λ����ʹ��
			str[j] = (k * 10 + str[j] - '0') / 2 + '0';	//str[j]:��λ��,��������,���¸�λ��
			k = t;										//����t��k
		}
		ans.push_back(k);								//��ʱ��kΪ,���һ������ʣ�µ�����,���÷����ڶ�����ȡ��ʱ�õ��������λ������(���ans)
		while ( str[i] == '0' ) i++;					//����������ʹ�ø�λ������0,��i++; ��:100 / 2 = 050 ��λ������0,����һ�δ�5��ʼ,���г�������
	}
}
//������һ������,���߲������Թ�һ��,������㷨�����
//case:40
//i = 0, length = strlen(str) = 2

//4 % 2 = 0 -> t -> k
//4 / 2 = 2 -> str[0]
//0 % 0 = 0 -> t -> k -> ans[0] = 0
//0 / 0 = 0 -> str[1]

//2 % 2 = 0 -> t -> k
//2 / 2 = 1 -> str[0]
//0 % 0 = 0 -> t -> k -> ans[1] = 0
//0 / 0 = 0 -> str[1] 

//1 % 2 = 1 -> t -> k
//1 / 2 = 0 -> str[0]
//10 % 2 = 0 -> t -> k -> ans[2] = 0
//10 / 2 = 5 -> str[1]

//str[0] == '0' -> i++ -> i = 1

//5 % 2 = 1 -> t -> k -> ans[3] = 1
//5 / 2 = 2 -> str[1]

//2 % 2 = 0 -> t -> k -> ans[4] = 0
//2 / 2 = 1 -> str[1]

//1 % 2 = 1 -> t -> k -> ans[5] = 0
//1 / 2 = 0 -> str[1]

//str[1] == '0' -> i++ -> i = 2

//for end

int main(){

	//str:���ַ�����ʽ�����ת����ʮ������
	char str[40];
	while ( scanf("%s", str) != EOF )
	{
		//ans:���ת����Ķ�������(�������ŵ�)(����ȡ�෨�ȵõ��������λ)
		vector<int> ans;

		//ת��
		conversion(str, ans);

		//�������ans,��Ϊת����Ķ�������
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
