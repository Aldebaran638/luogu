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

int k;
int result[20000] = {0};
int ans = 0;
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> k;

  for (int i = 10000; i <= 30000; i++)
  {
    int a = i / 100;
    int c = i % 1000;
    int b = (i % 10000) / 10;
    if (a % k == 0 && b % k == 0 && c % k == 0)
    {
      result[ans++] = i;
    }
  }
  if (ans == 0)
  {
    cout << "No" << endl;
  }
  else
  {
    for (int i = 0; i < ans; i++)
    {
      cout << result[i] << endl;
    }
  }
  return 0;
}