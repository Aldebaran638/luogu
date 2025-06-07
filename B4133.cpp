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
ll result = -(1e8 + 20);
ll maxx = -(1e8 + 20);

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int mid = 0;
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> mid;
    maxx = maxx + mid > mid ? maxx + mid : mid;
    result = maxx > result ? maxx : result;
  }
  cout << result;
  return 0;
}