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
vector<int> num;
const int N = 100 + 20;
int result;
bool isfind[N];
bool findnum(int i, int j, int mid)
{
  bool flag = 0;
  for (int k = 0; k < n; k++)
  {
    if (num[k] == mid && !isfind[k])
    {
      isfind[k] = 1;
      flag = 1;
      break;
    }
  }
  return flag;
}
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int mid;
    cin >> mid;
    num.push_back(mid);
  }
  for (int i = 0; i < num.size() - 1; i++)
  {
    for (int j = i + 1; j < num.size(); j++)
    {
      if (findnum(i, j, num[i] + num[j]))
      {
        result++;
      }
    }
  }
  cout << result;
  return 0;
}