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

int n, s;

const int N = 1e5 + 20;

int p[N], c[N];

int result = 0;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> p[i] >> c[i];

  return 0;
}