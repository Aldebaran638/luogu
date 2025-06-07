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
bool isexist[N];

int abs(int num)
{
  if (num < 0)
    return -num;
  else
    return num;
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int pre = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int mid;
    cin >> mid;
    if (i != 0)
    {
      if (abs(mid - pre) <= n - 1 && abs(mid - pre) >= 1)
      {
        isexist[abs(mid - pre)] = 1;
      }
    }
    pre = mid;
  }
  int isjolly = 1;
  for (int i = 1; i <= n - 1; i++)
  {
    if (!isexist[i])
    {
      isjolly = 0;
      break;
    }
  }
  if (isjolly)
  {
    cout << "Jolly" << endl;
  }
  else
  {
    cout << "Not jolly" << endl;
  }
  return 0;
}