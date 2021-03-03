#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

const int maxn = 1000;

int main(){

	//str:�ַ���
	//a:���滻�ĵ���
	//b:�����滻�ĵ���
	char str[maxn], a[maxn], b[maxn];

	//�����ַ���
	while ( cin.get(str, maxn) )
	{
		//��ȡ�س���
		getchar();

		//����a, b����
		cin.getline(a, maxn);
		cin.getline(b, maxn);
		
		//words:���������ַ����е�ÿ������
		vector<char> words[100];

		//i, j:����
		int i = 0, j = 0;

		//�����ַ���
		//��ȡ��ÿ�����ʴ���words��
		while ( str[i] != '\0' )
		{
			//�������ո�,���߱������ַ���ĩβ,�˳�while
			while ( str[i] != ' ' && str[i] != '\0' )
			{
				words[j].push_back(str[i]);
				i++;
			}
			//��������ܻ��е���ʱ,i++
			if (str[i] == ' ') i++;

			//j:ͳ�Ƶ��ʵĸ���
			j++;
		}

		//����words
		for (int i = 0; i < j; i++)
		{
			//result:�жϸõ����Ƿ�����滻�ĵ�����ͬ(Ĭ����ͬ)
			bool result = true;
			for (int k = 0; k < words[i].size(); k++)
			{
				if ( words[i][k] != a[k] )	//���õ�������滻���ʲ�ͬ
				{
					result = false;			//result = false
					break;					//break
				}
			}
			//���õ�������滻�ĵ�����ͬ
			if ( result == true )
			{
				words[i].clear();			//��ոõ���
				for (int k = 0; b[k] != '\0'; k++)	//���뽫���滻�ĵ���
				{
					words[i].push_back(b[k]);
				}
			}
			//�������
			for (int k = 0; k < words[i].size(); k++)
			{
				printf("%c", words[i][k]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
