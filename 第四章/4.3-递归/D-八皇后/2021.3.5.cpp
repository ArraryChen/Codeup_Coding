//�˻ʺ�����

#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

//count1:�˻ʺ���еķ�����
//n:���̵Ĺ�ģ,��������Ϊ8,����Ϊ8
int count1 = 0, n = 8;

//temp:���浱ǰ����������
//ans:������е�����(���ڰ˻ʺ��������92,����ά��Ϊ100)
vector<int> temp, ans[100];

//hashTable:����ĳһ���Ƿ��ѱ�ѡ��(false:δѡ��)
bool hashTable[100] = { false };


void generateP(int index){
	//����ʱ�Ѿ��ݹ�n+1����(Ҳ����˵temp���Ѿ���n������,˵��ÿһ���Ѿ������ӷ���)
	//��Ҫ���ðڷŷ����Ƿ����
	if ( index == n + 1 )
	{
		//flag:���,Ĭ���ǿ��е�
		bool flag = true;
		
		//����ÿһ��Ԫ��
		for (int i = 1; i <= n; i++)
		{
			//���ڵ�������Ԫ��iʱ,ǰ��������Ѿ���Ԫ��i�ȽϹ�,�����ٴαȽ�
			for (int j = i + 1; j <= n; j++)
			{
				//�ж�Ԫ��i��Ԫ��j�Ƿ���ͬһ�Խ�����
				//��i�� - ��j�� �Ĳ�ľ���ֵ = temp�еĵ�i��Ԫ�� - temp�еĵ�j��Ԫ�� �Ĳ�ľ���ֵʱ--->����i��jԪ����һ���Խ�����
				if ( abs(i - j) == abs(temp[i] - temp[j]) )	//�ѵ�֮��
				{
					flag = false;
					break;
				}
			}
			//���Ѿ��жϳ��÷���������,ֱ���˳�����,�����ٴν��м��
			if ( flag == false ) break;
		}
		//���÷�������,�����ans,ͬʱ����count1��һ
		if (flag) ans[count1++] = temp;
		return;
	}

	//��������л�û�е�n��,��Ҫ�ٴν���ɸѡ
	for (int x = 1; x <= n; x++)
	{
		//hashTable[x] == false,�ж�x���Ƿ�ѡ��
		if (hashTable[x] == false)
		{                           //δѡ��
			temp.push_back(x);		//�����е��кŷŽ�temp
			hashTable[x] = true;	//����hashTable[x] =  true ��ʾ�����ѱ�ѡ��
			generateP(index + 1);	//������һ�εݹ�
			hashTable[x] = false;	//�ݹ����,ȡ�����б�ѡ��,��ѡ����һ�н��еݹ�
			temp.pop_back();		//����temp
		}
	}
}

int main(){

	//�����кŴ�1��ʼ,Ϊ�˱�̷���,��temp[1]��ʼ�������,���ȴ��0��temp
	temp.push_back(0);

	//��1��ʼ
	generateP(1);

	//m:����������ݵ�����n
	int m;
	scanf("%d", &m);

	while ( m-- )
	{
		//check:������ĵ�check����
		int check;
		scanf("%d", &check);
		
		for (int i = 1; i < ans[check-1].size(); i++)
		{
			printf("%d", ans[check-1][i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
