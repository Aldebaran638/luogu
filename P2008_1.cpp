#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define int long long

// 题目数据
int n;
const int N = 1e8 + 20;
ll num[N];

// 纵坐标为子序列的长度，横坐标0为这一行最小值的坐标，横坐标1到结尾为该长度子序列的各个结尾值的坐标
vector<vector<int>> l;
// l有几个纵坐标
int lsize = 0;

// 每个人的分数
int result[N];

// 代表l中的数据
struct node
{
  int x, y;
};

node findm(int i)
{
  struct node m;
  if (i == 0)
  {
    m.y = 0, m.x = 0;
    return m;
  }
  int left = 1, right = lsize;
  if (num[i] < num[l[left][0]])
  {
    m.y = 0, m.x = 0;
  }
  else if (num[i] > num[l[right][0]])
  {
    m.y = right;
    // 再遍历l这一行的元素,找到字典序最小的,符合条件的值
    for (int j = 1; j < l[m.y].size(); j++)
    {
      if (num[i] >= l[m.y][j])
      {
        m.x = j;
        break;
      }
    }
  }
  else
  {
    // 二分求纵坐标
    while (right > left + 1)
    {
      if (num[i] >= num[l[(right + left) / 2][0]])
      {
        left = (right + left) / 2;
      }
      else if (num[i] < num[l[(right + left) / 2][0]])
      {
        right = (right + left) / 2 - 1;
      }
    }
    right = num[i] >= num[l[right][0]] ? right : left;
    m.y = right;
  }
  // 再遍历l这一行的元素,找到字典序最小的,符合条件的值
  for (int j = 1; j < l[m.y].size(); j++)
  {
    if (num[i] >= num[l[m.y][j]])
    {
      m.x = j;
      break;
    }
  }
  return m;
}

signed main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  // 输入题目数据
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> num[i];
    result[i] = num[i];
  }
  // 初始化l
  for (int i = 0; i < n + 1; i++)
  {
    l.push_back(vector<int>());
    l[i].push_back(0);
  }

  // 遍历num
  for (int i = 0; i < n; i++)
  {
    // 找合适的l中的坐标（适合在这个坐标对应的数后面加）
    node m = findm(i);
    // 如果找到了是第y行，就在l的y+1行添加一个数
    l[m.y + 1].push_back(i);
    l[m.y + 1][0] = num[l[m.y + 1][0]] >= num[i] ? i : l[m.y + 1][0];
    // （如果y大于目前的lsize，就新增一个有效行）
    if (m.y + 1 > lsize)
    {
      lsize++;
      l[m.y + 1][0] = i;
    }

    result[i] = result[l[m.y][m.x]] + num[i];
  }
  for (int i = 0; i < n; i++)
  {
    cout << result[i];
    if (i != n - 1)
      cout << " ";
  }
}


//comment:
//这代码不知道怎么改了...居然是全wa