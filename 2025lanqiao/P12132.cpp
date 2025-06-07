
//这题想了几轮才确定答案,说明水平是不足的
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

int n;
const int N=1e5+20;
ll result;

signed main(int argc, const char *argv[]){
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin>>n;
  for(int i=0;i<n;i++){
    int mid;cin>>mid;
    if(mid!=1){
      result++;
    }
  }
  cout<<result;
  return 0;
}