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
int maxl = 0;
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int l = 0;
  int pre = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    if (i != 0)
    {
      if (num == pre + 1)
        l++;
      else
      {
        maxl = max(l, maxl);
        l = 0;
      }
    }
    pre = num;
  }
  maxl = max(l, maxl);
  cout << maxl + 1 << endl;

  return 0;
}