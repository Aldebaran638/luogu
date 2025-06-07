// 这道题一开始看是很简单的
// 但是注意到到模拟过程,发现模拟次数大概是TK次.
// 而题目中的T最多为1e5,K则为1e9.
// 一般情况下认为计算机一秒钟能运行5e8次,所以极端情况会超时
// 所以这道题目直接模拟不能满分.猜测运行一定次数以后数据会逐渐趋近于一个值.
// 使用随机数据打表以后发现确实如此,故在原代码的基础上加上判断数据是否保持不变的语句用于退出循环

// 实际上是因为每进行一次迭代,三个数的极差会缩小一半(?)

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

int t, a, b, c, k;
int num[3];
signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> t;
  while (t--)
  {
    for (int i = 0; i < 3; i++)
      cin >> num[i];
    cin >> k;
    int _num[3];
    for (int i = 0; i < k; i++)
    {
      a = (num[1] + num[2]) / 2;
      b = (num[0] + num[2]) / 2;
      c = (num[1] + num[0]) / 2;
      // 判断数据是否不变.如果数据保持不变,那么后面的模拟都没有意义,直接跳出循环
      if (a == num[0] && b == num[1] && c == num[2])
        break;
      num[0] = a, num[1] = b, num[2] = c;
    }
    for (int i = 0; i < 3; i++)
      cout << num[i] << " ";
    cout << endl;
  }
  return 0;
}