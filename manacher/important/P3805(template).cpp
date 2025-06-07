#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<cstring>
#include<cstdio>
#include<cctype>

#define ll long long
using namespace std;
const int N=(1.1*(1e7)+20)*3;
char num[N],c;
int p[N],mid,r,numsize=2,ans;
void input(){
  num[0]='~',num[1]='|';
  while(isalpha(c=getchar())){
    num[numsize++]=c,num[numsize++]='|';
  }
  num[numsize++]='$';
}

signed main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  for(int i=1;i<numsize;i++){
    p[i]=min(p[mid*2-i],r-i+1);
    while(num[i-p[i]]==num[i+p[i]]) p[i]++;
    if(i+p[i]>r){r=i+p[i]-1;mid=i;}
    if(p[i]>ans) ans=p[i];
  }
  cout<<ans-1;
    return 0;
}
