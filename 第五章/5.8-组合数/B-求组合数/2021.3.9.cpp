#include<cstdio>
#include<iostream>

using namespace std;

float fact(int n){

	if ( n == 0 || n == 1 ) return 1;
	else return n * fact(n - 1);

}

int main(){

	int m, n;
	while ( scanf("%d %d", &m, &n) != EOF )
	{
		printf("%.0f\n", fact(m) / ( fact(n) * fact(m-n) ) );
	}

	system("pause");
	return 0;
}
