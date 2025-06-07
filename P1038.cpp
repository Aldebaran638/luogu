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

int a, b;

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> a >> b;
  int result = 0;
  for (int i = a; i <= b; i++)
  {
    if (abs(i) % 4 == 0 || abs(i) % 2 != 0)
    {
      result++;
    }
  }
  cout << result;
  return 0;
}