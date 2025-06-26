// 2025年6月26日
// FordFulkerson算法模板题
#include <bits/stdc++.h>

#define ll long long
using namespace std;

mutex mtx;
chrono::time_point<std::chrono::steady_clock> startt;
chrono::time_point<std::chrono::steady_clock> endt;

// 网络存储变量
int n, m, s, t;
const int N = 2e2 + 20, M = 5e3 + 20;
ll capacity[N][N];
// 若i，j为正向边，则j，i就一定是反向边
//  正向边的capacity一定大于0.反向边的capacity为0，但是flow大于0
ll flow[N][N];
// dfs算法变量
const ll INF = LLONG_MAX / 1e2;
list<int> dfsResultRoute; // 记录dfs路径
ll dfsResultValue = INF;  // 记录dfs路径中最小容量
bool isv[N];

ll result;
void input()
{
  cin >> n >> m >> s >> t;
  int u, v;
  ll w;

  for (int i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    capacity[u][v] = w;
  }
}

bool dfs(int tmp)
{
  if (isv[tmp])
    return false;
  if (tmp == t)
  {
    dfsResultRoute.push_front(tmp);
    return true;
  }

  isv[tmp] = 1;
  for (int i = 1; i <= n; i++)
    if (!isv[i])
    {
      // 处理正向边
      // 用capacity[tmp][i] - flow[tmp][i]>0判断某个边是否是反向边
      // 由于反向边的capacity[tmp][i]==0，所以这样一减一定会小于0
      if (capacity[tmp][i] - flow[tmp][i] > 0)
      {
        if (dfs(i))
        {
          dfsResultRoute.push_front(tmp);
          dfsResultValue = min(dfsResultValue, capacity[tmp][i] - flow[tmp][i]);
          return true;
        }
      }
      // 处理反向边
      // 反向边上有可退的流量
      else if (flow[i][tmp] > 0)
      {
        if (dfs(i))
        {
          dfsResultRoute.push_front(tmp);
          dfsResultValue = min(dfsResultValue, flow[i][tmp]);
          return true;
        }
      }
    }

  isv[tmp] = 0;
  return false;
}

void FordFulkerson()
{
  result = 0;
  while (1)
  {
    // DFS算法寻找路径
    dfsResultRoute.clear();
    dfsResultValue = INF;
    memset(isv, 0, sizeof(isv));
    if (dfs(s))
    {
      // 找到路径后就进行其他的计算
      // 根据dfsResultRoute对路径上所有的边空闲量-=dfsResultValue
      // 根据dfsResultRoute在路径上添加反向边
      // 沿增广路径更新流量
      auto it = dfsResultRoute.begin();
      int prev = *it++;
      while (it != dfsResultRoute.end())
      {
        int cur = *it++;
        // 如果是原始正向边
        if (capacity[prev][cur] > 0)
          flow[prev][cur] += dfsResultValue;
        else
          // 否则在反向边上退流
          flow[cur][prev] -= dfsResultValue;
        prev = cur;
      }
    }
    else
    {
      // 找不到路径就直接给result赋值;
      for (int i = 1; i <= n; i++)
        result += flow[s][i];
      return;
    }
  }
}

void output()
{
  cout << result << endl;
}

void Solution()
{
  input();
  FordFulkerson();
  output();
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  mtx.lock();
  startt = std::chrono::steady_clock::now();
#endif

  Solution();

#ifndef ONLINE_JUDGE
  endt = std::chrono::steady_clock::now();
  mtx.unlock();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endt - startt);
  int count = duration.count();
  cout << "运行时间:" << count << " 微秒";
#endif
  return 0;
}