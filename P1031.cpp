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
const int N = 100 + 20;
int num[N];
int sum = 0;
int result = 0;
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> num[i];
    sum += num[i];
  }
  sum /= n;
  for (int i = 0; i < n; i++)
  {
    num[i] -= (sum);
  }
  int s = 0;
  for (int i = 0; i < n; i++)
  {
    if (s != 0)
    {
      result += 1;
    }
    s += num[i];
  }
  cout << result << endl;
  return 0;
}