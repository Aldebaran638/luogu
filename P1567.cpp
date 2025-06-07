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
int maxl;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  int pre = 0;
  int l = 1;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    if (i != 0)
    {
      if (num > pre)
        l++;
      else
      {
        maxl = max(maxl, l);
        l = 1;
      }
    }
    pre = num;
  }
  maxl = max(maxl, l);
  cout << maxl << endl;
  return 0;
}