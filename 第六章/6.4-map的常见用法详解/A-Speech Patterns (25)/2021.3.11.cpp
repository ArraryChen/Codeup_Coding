#include<cstdio>
#include<map>
#include<string>
#include<iostream>

using namespace std;

//str_count:����ÿ������,��Ӧ���ֵĴ���
map<string , int> str_count;

//�������ַ����д�д��ĸ��ΪСд��ĸ
void change(string &str){

	int length = str.length();

	for (int i = 0; i < length; i++)
	{
		if ( str[i] >= 'A' && str[i] <= 'Z' ) str[i] = str[i] - 'A' + 'a';
	}
}

int main(){

	//str:�����ַ���
	string str;

	//getline()����:���ڶ��뺬�пո�����ַ���
	while ( getline(cin, str) )
	{
		//����д��ĸ��ΪСд��ĸ
		change(str);

		//length:�����ַ�������
		int length = str.length();

		//temp:���浥��
		string temp;

		//�м�,�����ѭ����������ӵȺ�,��Ϊ���һ�����ʵ��ж���Ҫ��������Ⱥ�
		for (int i = 0; i <= length; i++)
		{
			//�������ֻ�Сд��ĸ,�����ڵ��ʵ�һ����
			if ( str[i] >= '0' && str[i] <= '9' )
			{
				temp += str[i];
			}
			else if ( str[i] >= 'a' && str[i] <= 'z' )
			{
				temp += str[i];
			}
			//�����������ַ�,������������Ѿ���������
			//ת�뵽map�жϸõ����Ƿ���ֹ�
			else if ( !temp.empty() )
			{
				//��map���Ѿ��иõ���,������һ
				if ( str_count.find(temp) != str_count.end() ) 
					str_count[temp]++;
				//�����ʼ����Ӹõ��ʵ�map��
				else 
					str_count[temp] = 1;
				//��ոõ���,ת���¸����ʵ��ж�,���������
				temp.clear();
			}
		}

		//max_count:���ִ������ĵ��ʴ���
		//max_word:���ִ������ĵ���
		int max_count = 0;
		string max_word;

		//����map,�ҵ����ִ������ĵ���,������ֵĴ���
		for ( auto it = str_count.begin(); it != str_count.end(); it++ )
		{
			if ( it->second > max_count )
			{
				max_count = it->second;
				max_word = it->first;
			}
		}
		//���
		cout << max_word << " " << max_count << endl;
	}

	system("pause");
	return 0;
}
