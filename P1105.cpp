#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cctype>

#define ll long long
using namespace std;

int n;
const int N = 1e3 + 20;
int num[N][4];
bool compare(int *a, int *b)
{
  return a[1] < b[1];
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    num[i][0] = i + 1;
    cin >> num[i][1] >> num[i][2] >> num[i][3];
  }
  sort(num[0], num[n - 1], compare);
  for (int i = 0; i < n; i++)
  {
    
  }
  return 0;
}