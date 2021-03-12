//�ο�:https://www.jianshu.com/p/48a40bf9ad2c

#include<cstdio>
#include<string>
#include<map>
#include<queue>
#include<iostream>

using namespace std;

struct task{

	string name;	//������
	int priority;	//�������ȼ�

	friend bool operator < (task a, task b){	//�����������ȼ�
		if ( a.priority != b.priority )			//���ȼ���ͬʱ
			return a.priority > b.priority;		//priorityС�����ȼ���
		else
			return a.name > b.name;				//priority��ͬʱ,�ֵ���С�����ȼ���
	}

};

//load����:�����������ȼ�������priority_queue
void load(string s, priority_queue<task> &pq, map<string, int> &have){

	string word = "";	//������
	task t;				//����ṹ��,�ݴ浥�ʼ������ȼ�,���ڴ���priority_queue

	for (int i = 0; s[i] != '(' ; i++)	//�ҵ����������ǰ������
		word += s[i];

	if ( have[word] == 0 )				//��map��Ѱ��,��δ���ҵ���
	{
		t.name = word;					//���������ȼ����(��Ϊ���������κ�һ������ĺ�������)
		t.priority = 1;					//�������ȼ�
		have[word] = 1;					//����map
		pq.push(t);						//����priority_queue
	}
	s.erase(s.begin(), s.begin() + s.find("(") + 1);	//��ȥ��ںż���ǰ������,����֮����

										//��map���Ѿ�����word�����ȼ�,��have[word]��ľ���word�����ȼ�

	int temp = have[word] + 1;			//��Ҫ�����������,������Ȼtemp������Ǻ�����������ȼ� = ǰ���������ȼ� + 1

	word = "";							//���word

	for (int i = 0; i < s.size(); i++)	//������������
	{
		if ( (s[i] == ',' || s[i] == ')' ) && (word != "NULL" && have[word] == 0) )	//����������Ż�������(��������һ��task),��Ϊ�ղ��Ҳ�����priority���ҵ�
		{
			t.name = word;				//ͬ��
			t.priority = 1;
			have[word] = temp + 1;
			pq.push(t);
			word = "";					//�������task,���word
		}
		else
			word += s[i];				//����δ��������,word += s[i]
	}

}

int main(){

	//n:������
	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		//pq:�����ȼ�˳��(�����ȼ���ͬʱ���ֵ���)����ÿ������
		//have:����ÿ�����������ȼ�
		priority_queue<task> pq;
		map<string, int> have;

		//s:�����ǰ���������������
		string s;

		//ѭ������
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			load(s, pq, have);
		}

		//ѭ�����
		while ( !pq.empty() )
		{
			cout << pq.top().name;

			if ( pq.size() > 1 )
				cout << " ";
			else
				cout << endl;

			pq.pop();
		}
	}

	system("pause");
	return 0;
}
