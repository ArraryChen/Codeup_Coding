//#include<cstdio>
//#include<set>
//
//using namespace std;
//
//int main(){
//
//	//n:集合数
//	int n;
//	scanf("%d",&n);
//
//	//集合数
//	set<int> sets[51];
//
//	//cap:每个集合容量
//	//number:集合中的数
//	int cap=0;
//	int number=0;
//	for(int i=1;i<=n;i++){
//		scanf("%d",&cap);
//		for(int j=0;j<cap;j++){
//			scanf("%d",&number);
//			sets[i].insert(number);
//		}
//	}
//
//	//count:待查询的两两集合数
//	int count=0;
//	scanf("%d",&count);
//
//	//set_num1:待查询集合1
//	//set_num2:待查询集合2
//	int set_num1;
//	int set_num2;
//	for(int i=0;i<count;i++){
//		scanf("%d %d",&set_num1,&set_num2);
//
//		double same_count=0;//相同元素
//		double dis_count=0;	//不同元素
//							
//		set<int>::iterator it1=sets[set_num1].begin();
//		set<int>::iterator it2=sets[set_num2].begin();
//		for( ; it1!=sets[set_num1].end() && it2!=sets[set_num2].end();){
//			if(*it1==*it2){
//				++same_count;
//				++it1;
//				++it2;
//			}
//			else if(*it1 < *it2){
//				++dis_count;
//				++it1;
//			}
//			else{
//				++dis_count;
//				++it2;
//			}
//		}
//		if(it1!=sets[set_num1].end()){
//			++dis_count;
//			++it1;
//		}
//		if(it2!=sets[set_num2].end()){
//			++dis_count;
//			++it2;
//		}
//		printf("%.1lf%%\n",same_count/(same_count+dis_count)*100.0);	// 相同元素 / (不同元素+相同元素)
//	}
//
//	system("pause");
//	return 0;
//}