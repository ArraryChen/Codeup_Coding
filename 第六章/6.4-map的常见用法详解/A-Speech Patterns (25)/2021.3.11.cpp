#include<cstdio>
#include<map>
#include<string>
#include<iostream>

using namespace std;

//str_count:保存每个单词,对应出现的次数
map<string , int> str_count;

//将输入字符串中大写字母改为小写字母
void change(string &str){

	int length = str.length();

	for (int i = 0; i < length; i++)
	{
		if ( str[i] >= 'A' && str[i] <= 'Z' ) str[i] = str[i] - 'A' + 'a';
	}
}

int main(){

	//str:输入字符串
	string str;

	//getline()函数:用于读入含有空格符的字符串
	while ( getline(cin, str) )
	{
		//将大写字母改为小写字母
		change(str);

		//length:输入字符串长度
		int length = str.length();

		//temp:保存单词
		string temp;

		//切记,这里的循环条件必须加等号,因为最后一个单词的判断需要依靠这个等号
		for (int i = 0; i <= length; i++)
		{
			//遇到数字或小写字母,都属于单词的一部分
			if ( str[i] >= '0' && str[i] <= '9' )
			{
				temp += str[i];
			}
			else if ( str[i] >= 'a' && str[i] <= 'z' )
			{
				temp += str[i];
			}
			//遇到了其他字符,表明这个单词已经遍历结束
			//转入到map判断该单词是否出现过
			else if ( !temp.empty() )
			{
				//若map中已经有该单词,次数加一
				if ( str_count.find(temp) != str_count.end() ) 
					str_count[temp]++;
				//否则初始化添加该单词到map中
				else 
					str_count[temp] = 1;
				//清空该单词,转到下个单词的判断,或结束遍历
				temp.clear();
			}
		}

		//max_count:出现次数最多的单词次数
		//max_word:出现次数最多的单词
		int max_count = 0;
		string max_word;

		//遍历map,找到出现次数最多的单词,及其出现的次数
		for ( auto it = str_count.begin(); it != str_count.end(); it++ )
		{
			if ( it->second > max_count )
			{
				max_count = it->second;
				max_word = it->first;
			}
		}
		//输出
		cout << max_word << " " << max_count << endl;
	}

	system("pause");
	return 0;
}
