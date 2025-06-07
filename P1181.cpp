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

int n, m;
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  cin >> n >> m;
  int s = 0, mid = 0;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> mid;
    if (s + mid > m)
    {
      s = mid;
      ans++;
    }
    else
    {
      s += mid;
    }
  }
  ans++;
  cout << ans << endl;

  return 0;
}