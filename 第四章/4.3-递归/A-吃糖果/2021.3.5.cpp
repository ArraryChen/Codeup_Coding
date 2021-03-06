#include<cstdio>
#include<iostream>

using namespace std;

int func(int n){

	if ( n == 1 ) return 1;
	else if ( n == 2 ) return 2;
	else return func( n - 1 ) + func ( n - 2 );
}


int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		printf("%d\n", func(n));
	}

	system("pause");
	return 0;
}