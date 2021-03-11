#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

//maxn:最大学生数
//maxk:最大课程数
const int maxn = 40010;
const int maxk = 2510;

//names:所有学生姓名
//courses:所有课程编号
char names[maxn][5];
vector<int> courses[maxk];//courses内存放的是学生的编号

bool cmp(int a,int b){
	return strcmp(names[a],names[b])<0;
}

int main(){

	//n:学生数
	//k:课程数
	int n,k;
	scanf("%d %d",&n,&k);

	//count_course:注册的课程数
	//num_course:课程号
	int count_course;
	int num_course;

	//循环输入学生信息 用数组的下标代表一个学生
	//也就是说每个学生有一个编号
	for(int i=1;i<=n;i++){
		scanf("%s %d",names[i],&count_course);
		//循环输入该名学生注册的课程编号
		for(int j=0;j<count_course;j++){
			scanf("%d",&num_course);
			courses[num_course].push_back(i);
		}
	}

	//循环输出 课程编号 课程内学生信息
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,courses[i].size());
		//将注册该课程的学生按姓名递增顺序排序
		sort(courses[i].begin(),courses[i].end(),cmp);
		//循环输出学生姓名
		for(int j=0;j<courses[i].size();j++){
			printf("%s\n",names[courses[i][j]]);
		}
	}
	system("pause");
	return 0;
}