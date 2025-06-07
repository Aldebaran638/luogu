//基础算法常规题 

#include<bits/stdc++.h>

#define int long long
#define endl '\n';

using namespace std;

int n,m;
const int N=5e5+20;
set<int> num;

int cadd=0;


inline void op1(int b){
	cadd-=b;
}

void op2(){
	set<int>::iterator _it=num.upper_bound(cadd);
	int sum=0,sumn=0;
	for(;_it!=num.end();++_it){
		sum+=*_it;
		sumn++;
	}
	cout<<sum+sumn*(-cadd)<<endl;
	
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	ios::sync_with_stdio(false);	
	cin>>n>>m;
	int mid;
	for(int i=0;i<n;i++){
		cin>>mid;
		num.insert(mid);
	}
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		if(a==1){
			int b;cin>>b;
			op1(b);
		}
		else{
			op2();
		}
	}
}
