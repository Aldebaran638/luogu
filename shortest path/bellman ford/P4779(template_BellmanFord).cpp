// BellmanFord算法的模板(本代码是过不去模板题的)
// 时间复杂度O(n*m)n为点数,m为边数
// 可以处理无环的负权图,有环但非负权图
// 比Dijkstra适用性更广,但效率更低
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m, s;
const int M = 2e5 + 20;
// 由于BellmanFord只关心边而不强调边必须起点是什么,所以只需要一维数组存储
struct node
{
  int start;
  int end;
  ll w;
  node() = default;
  node(int _start, int _end, int _w) : start(_start), end(_end), w(_w) {}
};
vector<node> edges;

const int N = 1e5 + 20;
ll result[N];

void input()
{
  cin >> n >> m >> s;
  s -= 1;
  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    edges.push_back(node(a - 1, b - 1, w));
  }
}

void bellmanford()
{
  // 初始化结果数组
  result[s] = 0;
  for (int i = 1; i < n; i++)
    result[i] = LLONG_MAX / 1e2;

  // 用于判断当前轮次是否改变,若未改变,直接跳出循环
  bool ischange = 0;
  // 进行 顶点数-1 轮循环更新最短路径(进行 顶点数-1 轮是因为无环图最多就 顶点数-1 条边)
  for (int i = 0; i < n - 1; i++)
  {
    ischange = 0;
    node mid;
    // 遍历每一条边
    for (int j = 0; j < edges.size(); j++)
    {
      mid = edges[j];
      // 遍历到的边如果出现 总起点到边的起点的最短距离+这条边的距离 < 当前总起点到边的终点的最短距离
      if (result[mid.end] > result[mid.start] + mid.w)
      {
        // 就更新当前总起点到边的终点的最短距离
        result[mid.end] = result[mid.start] + mid.w;
        // 标记,该轮次改变了至少一个result元素
        ischange = 1;
      }
    }
    // 如果当前轮次未改变任何结果,说明接下来的轮次也不会改变(因为之后每一轮做的事情都是一样的).直接跳出循环
    if (!ischange)
      break;
  }

  // node mid;
  // ischange = 0;
  // // 顶点数-1 轮完成后,再进行一次检查.如果更新,说明检测到负权环.此时只能返回检测到负权环的结果,无法算出正确答案
  // for (int j = 0; j < edges.size(); j++)
  // {
  //   mid = edges[j];
  //   if (result[mid.end] > result[mid.start] + mid.w)
  //   {
  //     result[mid.end] = result[mid.start] + mid.w;
  //     ischange = 1;
  //   }
  // }
  // if(ischange){
  //   //说明有负权环的存在
  // }
}

void output()
{
  for (int i = 0; i < n; i++)
    cout << result[i] << " ";
  cout << endl;
}

signed
main(int argc, const char *argv[])
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  input();
  bellmanford();
  output();
  return 0;
}