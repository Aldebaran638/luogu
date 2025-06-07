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

int n1; // n1为num,stat长度,
const int N = 1e5 + 20;

// 第一问参数
int n2; // 第一问答案,n2为fi长度
int num[N];
int stat[N];
int fi[N];

// 第二问参数
set<int> h; // 目前的导弹系统能拦截的高度

void updatefi(int i)
{
  int left = 1, right = n2;
  if (num[i] > fi[left])
  {
    if (fi[left] == 0)
      n2++;
    fi[left] = num[i];
  }

  else if (num[i] < fi[right])
  {
    fi[right + 1] = num[i];
    n2++;
  }
  else
  {
    // 如果需要查找的目标在fi已经存在的数字当中,就二分查找
    while (right > left + 1)
    {
      int mid = (right + left) / 2;
      if (num[i] > fi[mid])
        right = mid - 1;
      else if (num[i] <= fi[mid])
        left = mid;
    }
    right = fi[right] >= num[i] ? right : left;
    fi[right + 1] = fi[right + 1] >= num[i] ? fi[right + 1] : num[i];
    n2 = right + 1 > n2 ? right + 1 : n2;
  }
}

void updateh(int i)
{
  set<int>::iterator it = h.lower_bound(num[i]);
  if (it != h.end())
  {
    h.erase(it);
  }
  h.insert(num[i]);
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  while (scanf("%d", &num[n1++]) != EOF)
    ;
  n1--;
  for (int i = 0; i < n1; i++)
  {
    // 二分查找合适的fi
    updatefi(i);
    updateh(i);
  }
  cout << n2 << endl;
  cout << h.size() << endl;
  return 0;
}