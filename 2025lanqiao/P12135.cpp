//纯分情况模拟题
//这种题硬让我想是可以想出来的,但是第一次做出的答案一定有错误,而且后续排查故障也可能排查不全
//更别说一次全对了
//1:代码写错.比如num[0]==num[1]==1就不是我想的那个意思.
//2:逻辑问题.比如有的地方没有result++,以及后半段如果没有#了怎么办(一开始是没有想到要加result2的)
//总之虽然逻辑清晰,但是很难对


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
const int N = 1e6 + 20;
char _map[2][N];

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  // 输入图
  char c;
  for (int i = 0; i < 2; i++)
  {
    n = 0;
    while (c = getchar())
    {
      if (c == '\n' || c == EOF)
      {
        break;
      }
      _map[i][n++] = c;
    }
  }
  // 遍历_map
  bool is1 = 0;         // 遍历到目前,是否出现过#
  bool pre[2] = {0, 0}; // 上一排水质检测器分布情况
  bool flag = 0;        // 上一排水质检测器分布情况是否是特殊情况
  bool now[2] = {0, 0}; // 这一排水质检测器分布情况
  int result = 0;       // 结果
  int result2 = 0;      // 记录到现在为止已经连续几次没有出现#了
  for (int j = 0; j < n; j++)
  {
    bool isjin = 0;
    for (int i = 0; i < 2; i++)
    {
      if (_map[i][j] == '#')
      {
        isjin = 1, now[i] = 1;
      }
      else
      {
        now[i] = 0;
      }
    }
    if (!is1)
    {
      if (isjin)
        is1 = 1;
    }
    else
    {
      // 在is1为1时,不可能出现pre两个0的情况

      if (now[0] == 0 && now[1] == 0)
      {
        result2++;
      }
      else
      {
        result2 = 0;
      }

      // 两种大情况
      // 第一种大情况:pre只有一个#

      if (pre[0] != pre[1])
      {
        // 交叉
        if (pre[0] != now[0] && pre[1] != now[1])
        {
          result++;
          if (now[0] != 1)
          {
            now[0] = 1;
          }
          else
          {
            now[1] = 1;
          }
          flag = 0;
        }
        // 全等
        else if ((pre[0] == now[0]) && (pre[1] == now[1]))
        {
          // 什么都不干
          flag = 0;
        }
        // 一等一不等(说明now有两个#或者没有)
        else
        {
          // 没有#
          if (now[0] != 1)
          {
            result++;
            now[0] = pre[0], now[1] = pre[1];
          }
          flag = 0;
        }
      }
      // 第二种大情况:pre有两个#
      else if (pre[0] == pre[1] == 1)
      {
        // 如果是特殊情况
        if (flag)
        {
          // now有一个#
          if (now[0] != now[1])
          {
            // 解除特殊情况(已经确定#的方位)
            flag = 0;
          }
          // now有两个#
          else if ((now[0] == now[1]) && (now[0] == 1))
          {
            // 解除特殊情况
            flag = 0;
          }
          // now没有#
          else
          {
            // 这时候now为特殊情况
            now[0] = 1, now[1] = 1;
            // 标记为特殊情况
            flag = 1;
            result++;
          }
        }
        // 如果不是特殊情况
        else
        {
          // now有一个#
          if (now[0] != now[1])
          {
            // 什么都不干
            flag = 0;
          }
          // 两个#
          else if ((now[0] == now[1]) && (now[0] == 1))
          {
            // 什么都不干
            flag = 0;
          }
          // 两个点
          else
          {
            // 进入特殊情况
            flag = 1;
            result++;
          }
        }
      }
    }
    for (int k = 0; k < 2; k++)
    {
      pre[k] = now[k];
    }
  }
  cout << result-result2;
  return 0;
}