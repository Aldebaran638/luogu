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

int n, ans;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int a, b, l=0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> b;
    if (i != 0)
    {
      if (a > b)
      {
        l=1;
      }
      else if (a < b)
      {
        if (l > 0)
        {
          ans++;
          l--;
        }
      }
    }
    a = b;
  }
  cout << ans << endl;
  return 0;
}
