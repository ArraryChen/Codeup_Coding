#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 10010;

void vowels(char str1[], char str2[]){

	int i = 0, j = 0;

	while ( str1[i] != '\0' )
	{
		if ( str1[i] == 'a' || str1[i] == 'A' ) str2[j++] = str1[i];
		else if ( str1[i] == 'e' || str1[i] == 'E' ) str2[j++] = str1[i];
		else if ( str1[i] == 'i' || str1[i] == 'I' ) str2[j++] = str1[i];
		else if ( str1[i] == 'o' || str1[i] == 'O' ) str2[j++] = str1[i];
		else if ( str1[i] == 'u' || str1[i] == 'U' ) str2[j++] = str1[i];

		i++;
	}
	str2[j++] = '\0';
}


int main(){

	char str1[maxn], str2[maxn];
	scanf("%s", str1);
	
	vowels(str1, str2);

	printf("%s\n", str2);

	system("pause");
	return 0;
}
