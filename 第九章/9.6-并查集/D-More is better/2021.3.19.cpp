//²Î¿¼: https://meteorrain.blog.csdn.net/article/details/81611408?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control&dist_request_id=1328680.10859.16161566203968089&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control

#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
const int maxn=10000010;
int father[maxn]={0},num[maxn];
int maxnum;
 
int findFather(int a)
{
	int x=a;
	while(x!=father[x])
	{
		x=father[x];
	}
	while(a!=father[a])
	{
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void Union(int a, int b)
{
	int A=findFather(a);
	int B=findFather(b);
	if(A!=B)
	{
		father[A]=B;
		num[B]+=num[A];
		if(maxnum<num[B])
			maxnum=num[B];
	}
}
void init(int n)
{
	father[n]=n;
	num[n]=1;
}
int main()
{
	int n,dot1,dot2;
	vector<pair<int,int> > input;
    while(~scanf("%d",&n))
    {
    	if(n==0)
    	{
    		printf("1\n");
    		continue;
		}
    	input.clear();
    	for(int i=0;i<n;++i)
    	{
    		scanf("%d %d",&dot1,&dot2);
			init(dot1);
			init(dot2);
			input.push_back(make_pair(dot1,dot2));
		}
		maxnum=0;
		for(int i=0;i<input.size();++i)
		{
			Union(input[i].first,input[i].second);
		}
		printf("%d\n",maxnum);
	}
    return 0;
}