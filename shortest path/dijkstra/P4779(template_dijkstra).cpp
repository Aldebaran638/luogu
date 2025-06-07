// 迪杰斯特拉算法模板题
// 时间复杂度O((n+m)logn)n为点数,m为边数
// 可以处理无环的非负权图,有环但非负权图
// 比BellmanFord效率更高,但适用面较小(无法处理无环负权图)
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define MINT INT_MAX

// 点的个数,边的个数,出发点
int n, m, s;
const int N = 1e5 + 20;
// 邻接表
vector<pair<int, ll>> edges[N];

// pq中的元素结构体
struct node
{
  int pos;
  int dis;
  node(int _pos, int _dis) : pos(_pos), dis(_dis) {}
  bool operator<(const node &_node) const
  {
    return dis > _node.dis;
  }
};
// 优先队列用于找到目前可以添加为"已经确认最短路径点"的点
priority_queue<node> pq;

// 结果数组
ll result[N];

// 根据n的大小输入图的邻接矩阵edges
void input()
{
  cin >> n >> m >> s;

  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    edges[a - 1].emplace_back(b - 1, w);
  }
}

// 使用迪杰斯特拉算法更新结果数组result
void dijkstra()
{
  // 先初始化堆和vis,result数组
  pq.push(node(s - 1, 0));

  for (int i = 0; i < n; i++)
    result[i] = LLONG_MAX / 1e2;

  while (!pq.empty())
  {
    // 每次取出来堆顶元素,即当前最佳点
    node mid = pq.top();
    pq.pop();

    // 如果当前最佳点是已经看过的(他的距离小于结果中的距离,说明其已经被dijkstra算法判定为已经确定最小距离的点了),直接跳过
    if (mid.dis > result[mid.pos])
      continue;

    // 如果没看过,就把他加入已经确认的点的集合
    result[mid.pos] = mid.dis;

    // 根据新加入的已经确认的点,更新他的邻居相关的信息
    for (int i = 0; i < edges[mid.pos].size(); i++)
      if (result[mid.pos] + edges[mid.pos][i].second < result[edges[mid.pos][i].first])
        pq.emplace(edges[mid.pos][i].first, edges[mid.pos][i].second + result[mid.pos]);
  }
}

// 将最终得到的结果数组输出
void output()
{
  // for (int i = 0; i < n; i++)
  //   cout << result[i] << " ";
  // cout << endl;
  // 这里保证题目可达
  for (int i = 0; i < n; i++)
    cout << result[i] << " ";
  cout << endl;
}

signed main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  dijkstra();
  output();
  return 0;
}
