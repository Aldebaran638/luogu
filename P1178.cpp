//������������Ŀ�ѵ���Ǹ�������,���м���˼���.
// ��������һ��ȡһ������,Ȼ��������������������˼���,����������������ļ������. 

//Zeller��ʽ���ڼ����������������ڼ�
 
#include<bits/stdc++.h>
#define ll long long

using namespace std;

//��һ�������ǻ�����
int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeapyear(int y){
	return ((y%4==0&&y%100!=0)||y%400==0);
} 
double gapdays(int sy,int y,int m,int d){
	double result=0; 
	//������ݴ�����������
	for(int i=sy;i<y;i++){
		result+=365;
		if(isLeapyear(i)){
			result++;
		}
	}
	//�����·ݴ�����������
	for(int i=1;i<m;i++){
		result+=md[i];
		if(i==2&&isLeapyear(y)){
			result++;
		}
	}
	result+=(d-1); 
	return result;
} 

int py,pm,pd;
int m,d;

const int N=1e4;
int input[N][2];

double result;

bool cmp(const int* a, const int* b) {
    if (a[0] != b[0]) {
        return a[0] > b[0];
    } else {
        return a[1] > b[1];
    }
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int n;cin>>n;
	py=3999,pm=12,pd=31;
	for(int i=0;i<n;i++){
		cin>>input[i][0]>>input[i][1]; 
	}
	//sort(input,input+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(input[j][0]!=input[j+1][0]){
				if(input[j][0]>input[j+1][0]) swap(input[j],input[j+1]);
			
			}
			else{
				if(input[j][1]>input[j+1][1]) swap(input[j],input[j+1]);
			}
		}
	}
	for(int i=0;i<n;i++){
		m=input[i][0],d=input[i][1];
		result=max(gapdays(3999,4000,m,d)-gapdays(3999,py,pm,pd)-1,result);
		py=4000,pm=m,pd=d;
	}
	m=1,d=1;
	result=max(gapdays(3999,4001,m,d)-gapdays(3999,py,pm,pd)-1,result);
	cout<<round(result*24*60*60/366.0)<<endl;
}
