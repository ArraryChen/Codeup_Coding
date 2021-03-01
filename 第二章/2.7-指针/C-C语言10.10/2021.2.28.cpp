#include<cstdio>
#include<iostream>

using namespace std;

char *a = "I love China!";

int main(){

	int n;
	scanf("%d", &n);

	a = a + n;

	while ( *a != '\0' )
	{
		printf("%c", *a++);
	}
	printf("\n");

	system("pause");
	return 0;
}
