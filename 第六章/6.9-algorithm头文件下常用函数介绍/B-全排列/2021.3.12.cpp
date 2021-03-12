#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	char str[10];
	while ( scanf("%s", str) != EOF && strlen(str) )
	{
		int length = strlen(str);

		do
		{
			printf("%s\n", str);
		} while ( next_permutation(str, str + length) );
	
		printf("\n");
	}

	system("pause");
	return 0;
}
