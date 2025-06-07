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
const int N = 1e4 + 20;
int num[N];
// a为记录最长子序列长度,b记录和的大小
int a[N];
long long b[N];

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
    b[i] = num[i];
  }
  // a[0] = 1;
  // 这句话不能加
  // 默认情况下,肯定所有数组成的最长子序列长度都是1.
  // 但由于这个代码中,b的所有值默认都是0,所以b的0代表最长子序列为1
  // 如果直接令a[0]=1,那相当于0处的值,他对应的最长不降子序列长度为2
  // 这肯定会对后面a元素的生成造成问题.
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (num[j] <= num[i] && a[j] >= a[i])
      {
        a[i] = a[j] + 1, b[i] = b[j] + num[i];
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << b[i] << " ";
  return 0;
}
// comment:
// 这是按照n方思路,并照着题解写的AC代码