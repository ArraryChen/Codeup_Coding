#include<cstdio>
#include<iostream>

using namespace std;

int Fab(int n){

	if ( n == 1 ) return 1;
	else if ( n == 2 ) return 1;
	else return Fab( n-1 ) + Fab( n - 2 );

}


int main(){

	int n;
	scanf("%d", &n);

	int sum = Fab(n);

	printf("%d\n", sum);

	system("pause");
	return 0;
}
