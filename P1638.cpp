#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cctype>

#define ll long long
using namespace std;
const int N = 1e6+20;
int n, m, a, b, num[N];
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
  int left = 0, right = 0, formated = 0;
  unordered_map<int, int> window;
  for (int i = 1; i < m; i++)
  {
    window[i] = 0;
  }
  int result = N + 1;
  for (right = 0; right < n; right++)
  {
    window[num[right]]++;
    if (window[num[right]] == 1)
    {
      formated++;
    }
    while (left <= right && formated == m)
    {
      if (right - left + 1 < result)
      {
        result = right - left + 1;
        a = left, b = right;
      }
      window[num[left]] -= 1;
      if (window[num[left]] == 0)
      {
        formated -= 1;
      }
      left++;
    }
  }
  cout << a + 1 << " " << b + 1 << endl;
  return 0;
}