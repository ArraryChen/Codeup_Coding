#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int a, b;

	while ( scanf("%d %d", &a, &b) != EOF , a || b )
	{
		printf("%d\n", a + b);
	}

	system("pause");
	return 0;
}
