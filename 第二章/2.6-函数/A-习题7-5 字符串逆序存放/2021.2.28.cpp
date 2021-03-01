#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 10010;

void reverseStr(char str[]){

	int length = strlen(str);

	for (int i = 0; i < length / 2; i++)
	{
		char temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1 ] = temp;
	}

}


int main(){

	char str[maxn];
	scanf("%s", str);

	reverseStr(str);

	printf("%s", str);
	
	system("pause");
	return 0;
}
