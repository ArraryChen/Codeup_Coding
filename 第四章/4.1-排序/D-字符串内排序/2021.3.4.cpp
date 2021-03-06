#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 210;

bool cmp(char a, char b){

	return a < b;

}

int main(){

	char str[maxn];
	while ( cin.getline(str, maxn) )
	{
		int len = strlen(str);

		sort(str, str + len, cmp);

		printf("%s\n", str);
	}

	system("pause");
	return 0;
}
