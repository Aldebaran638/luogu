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

double s;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> s;
  double totals = 0;
  double l = 2;
  int t = 0;
  while (totals < s)
  {
    totals += l;
    t++;
    l *= 0.98;
  }
  cout << t << endl;
  return 0;
}