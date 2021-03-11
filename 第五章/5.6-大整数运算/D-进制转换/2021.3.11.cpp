//²Î¿¼:https://blog.csdn.net/qq_41966660/article/details/112721327

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
 
struct bign{

    int d[3000];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};
 
bign change(char str[]){
    bign a;
    a.len = strlen(str);

    for(int i = 0; i < a.len; i++)
	{

        if(str[a.len - i - 1] >= 'A' && str[a.len - i - 1] <= 'Z')
            a.d[i] = str[a.len - i - 1] - 'A' + 10;
        else
			a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}
 
bign divide(bign a, int m, int b, int &r){

    bign c;
    c.len = a.len;

    for(int i = a.len-1; i >= 0; i--)
	{
        r = r * m + a.d[i];
        if( r < b )
			c.d[i] = 0;
        else
		{
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len-1] == 0) c.len--;
    return c;
}
 
void out(bign a){

    for(int i = a.len - 1; i >= 0; i--){
        if( a.d[i] >= 0 && a.d[i] <= 9 )
            printf("%d", a.d[i]);
        else 
			printf("%c", a.d[i] - 10 + 'a');
    }
}
 
int main() {
    int m, n;

    while( scanf("%d %d", &m, &n)!=EOF )
	{
        char str[1001];
        int r;
        scanf("%s", str);

        if( strlen(str)==1 && str[0]=='0' )
		{
            printf("%d\n", 0);
        }
        else
		{
            bign a = change(str);
            bign c;
            int num = 0;
            do
			{
                r = 0;
                a = divide(a, m, n, r);
                c.d[num++] = r;
                c.len++;
            }while( a.len!=1||(a.len==1&&a.d[0]!=0) );

            out(c);
            printf("\n");
        }
    }
	system("pause");
    return 0;
}