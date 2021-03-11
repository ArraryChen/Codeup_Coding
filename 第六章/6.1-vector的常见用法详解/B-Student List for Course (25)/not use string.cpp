#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

//maxn:���ѧ����
//maxk:���γ���
const int maxn = 40010;
const int maxk = 2510;

//names:����ѧ������
//courses:���пγ̱��
char names[maxn][5];
vector<int> courses[maxk];//courses�ڴ�ŵ���ѧ���ı��

bool cmp(int a,int b){
	return strcmp(names[a],names[b])<0;
}

int main(){

	//n:ѧ����
	//k:�γ���
	int n,k;
	scanf("%d %d",&n,&k);

	//count_course:ע��Ŀγ���
	//num_course:�γ̺�
	int count_course;
	int num_course;

	//ѭ������ѧ����Ϣ ��������±����һ��ѧ��
	//Ҳ����˵ÿ��ѧ����һ�����
	for(int i=1;i<=n;i++){
		scanf("%s %d",names[i],&count_course);
		//ѭ���������ѧ��ע��Ŀγ̱��
		for(int j=0;j<count_course;j++){
			scanf("%d",&num_course);
			courses[num_course].push_back(i);
		}
	}

	//ѭ����� �γ̱�� �γ���ѧ����Ϣ
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,courses[i].size());
		//��ע��ÿγ̵�ѧ������������˳������
		sort(courses[i].begin(),courses[i].end(),cmp);
		//ѭ�����ѧ������
		for(int j=0;j<courses[i].size();j++){
			printf("%s\n",names[courses[i][j]]);
		}
	}
	system("pause");
	return 0;
}