//��������ȽϷ���

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 10000;

int main(){

	//str1:���ַ���
	//str2:�����ַ���
	char str1[maxn], str2[maxn];
	scanf("%s", str1);
	getchar();
	
	//str1_len:���ַ����ĳ���
	int str1_len = strlen(str1);

	//ѭ�����������ַ���
	while ( cin.getline(str2, maxn) )
	{
		//i:���������ַ�����,��ǰ�������ַ�����
		int i = 0;

		//���������ַ�����β��ʱ,�˳�whileѭ��
		while ( str2[i] != '\0' )
		{
			//j:������ַ�����λ��
			int j = 0;

			//temp_pos:���浱ǰ�ַ�����λ��
			int temp_pos = i;
			
			//�жϵ�ǰ�ַ��Ƿ�Ϊ�ո�
			if ( str2[i] == ' ' )
			{
				//��Ϊ�ո�,���ԴӺ���ǰ�ķ�ʽ��ǰ����
				while ( str2[i] != '\0' )
				{
					str2[i] = str2[i+1];
					i++;
				}
				//�˻ص��ո��λ��,����ʱ�Ŀո��Ѿ��������ַ�������
				i = temp_pos;
			}

			//�õ�ǰ�������ִ��Ͷ��ַ����Ƚ�

			//���Լ������бȽϵ����: 1.����ĸ�ַ�����ͬ	2.��ĸ�ַ�,����Сд��ͬ
			while ( str2[i] == str1[j] || str2[i] == str1[j] - 'a' + 'A' || str2[i] == str1[j] - 'A' + 'a' )
			{
				i++;
				j++;
				if ( j == str1_len ) break;
			}

			//�����������ַ���β��ʱ
			if( j == str1_len )
			{
				//��ǰ���󸲸ǵ������ַ����еĶ��ַ�
				i = temp_pos;
				j = temp_pos + str1_len;

				//ֱ�������ַ�����β��
				while ( str2[j] != '\0' )
				{
					str2[i] = str2[j];
					i++;
					j++;
				}
				//�����Ͻ�����
				str2[i] = '\0';
				i = temp_pos;
			}
			//��û��,�������һ���ַ��ıȽ�
			else 
			{
				i = temp_pos;
				i++;
			}
		}//while end

		//���
		printf("%s\n", str2);
	}

	system("pause");
	return 0;
}
