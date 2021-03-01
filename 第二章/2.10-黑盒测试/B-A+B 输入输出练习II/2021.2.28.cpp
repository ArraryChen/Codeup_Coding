#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	int a, b;

	while ( n != 0 )
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);

		n--;
	}

	system("pause");
	return 0;
}
