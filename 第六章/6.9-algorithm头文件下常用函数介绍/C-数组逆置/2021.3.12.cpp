#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	string str;
	while ( getline(cin, str) && str.length() )
	{
		reverse(str.begin(), str.end());

		cout << str << endl;
	}

	system("pause");
	return 0;
}
