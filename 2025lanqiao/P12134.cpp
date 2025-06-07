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
const int N = 1e5 + 20, M = 1e5 + 20;

int num[N], l[N]; // 前者记录画价值,后者记录价值差

ll result; // 记录结果

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> num[i];
  }
  sort(num, num + n);
  for (int i = 0; i < n - 1; i++)
  {
    l[i] = abs(num[i] * num[i] - num[i + 1] * num[i + 1]);
  }
  int i = 0, j = i + m - 1 - 1;
  ll sum = 0;

  for (int k = i; k <= j; k++)
  {
    sum += l[k];
  }
  result = sum;
  i++, j++;
  for (; j < n - 1; j++, i++)
  {
    sum += l[j], sum -= l[i - 1];
    result = min(result, sum);
  }
  cout << result;
  return 0;
}