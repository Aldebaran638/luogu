# C++算法竞赛参考手册

## 常用头文件
```cpp
#include <iostream>      // 输入输出
#include <vector>        // 动态数组
#include <string>        // 字符串
#include <algorithm>     // 算法库
#include <map>           // 映射
#include <set>           // 集合
#include <queue>         // 队列
#include <stack>         // 栈
#include <unordered_map> // 哈希表
#include <unordered_set> // 哈希集合
#include <numeric>       // 数值算法
#include <cmath>         // 数学函数
#include <climits>       // 极限值
```

## 模版
```cpp
#include <bits/stdc++.h>

#define int long long
using namespace std;

struct Flower {
    int va;
    int l, r;

    Flower(int v, int a, int b) : va(v), l(a), r(b) {}
};

void QAQ() {
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("D:/Program/in.in", "r", stdin);
    freopen("D:/Program/out.out", "w", stdout);
#endif
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        QAQ();
    }
    return 0;
}

```

## 输入输出优化
```cpp
// 加速输入输出
ios::sync_with_stdio(false);
cin.tie(nullptr);

// 文件输入输出
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

## 常用数据结构

### 向量（Vector）
```cpp
vector<int> v;
v.push_back(10);        // 尾部添加元素
v.pop_back();           // 删除尾部元素
v.size();               // 大小
v.empty();              // 是否为空
v.clear();              // 清空
v.resize(10);           // 调整大小
v.begin(), v.end();     // 迭代器
```

### 队列和优先队列
```cpp
queue<int> q;
q.push(x);              // 入队
q.pop();                // 出队
q.front();              // 队首元素
q.size(), q.empty();

// 优先队列（默认大根堆）
priority_queue<int> pq;
// 小根堆
priority_queue<int, vector<int>, greater<int>> min_pq;
```

### 集合（Set）
```cpp
set<int> s;             // 有序集合
s.insert(x);            // 插入
s.erase(x);             // 删除
s.count(x);             // 计数
s.find(x);              // 查找

unordered_set<int> us;  // 哈希集合，O(1)查找
```

### 映射（Map）
```cpp
map<string, int> m;     // 有序映射
m["key"] = value;       // 插入/更新
m.erase("key");         // 删除
m.count("key");         // 计数
m.find("key");          // 查找

unordered_map<string, int> um; // 哈希映射，O(1)查找
```

## 算法库函数

### 排序与查找
```cpp
sort(v.begin(), v.end());                  // 默认升序
sort(v.begin(), v.end(), greater<int>());  // 降序
reverse(v.begin(), v.end());               // 反转

// 二分查找
binary_search(v.begin(), v.end(), x);      // 是否存在
lower_bound(v.begin(), v.end(), x);        // 第一个 >= x 的位置
upper_bound(v.begin(), v.end(), x);        // 第一个 > x 的位置
```

### 数值算法
```cpp
accumulate(v.begin(), v.end(), 0);         // 求和
*max_element(v.begin(), v.end());          // 最大值
*min_element(v.begin(), v.end());          // 最小值
count(v.begin(), v.end(), x);              // 元素计数
```

## 数论算法

### 基础定理

#### 费马小定理
若 p 为质数，对任意整数 a，有：
- a^p ≡ a (mod p)
- 若 a 不是 p 的倍数，则 a^(p-1) ≡ 1 (mod p)

```cpp
// 检验费马小定理
bool check_fermat(int a, int p) {
    return fast_pow(a, p, p) == a % p;
}
```

#### 欧拉定理
若 a 与 n 互质，则 a^φ(n) ≡ 1 (mod n)，其中 φ(n) 为欧拉函数

```cpp
// 计算欧拉函数
int euler_phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            result = result / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) result = result / n * (n - 1);
    return result;
}
```

#### 威尔逊定理
p 是质数当且仅当 (p-1)! ≡ -1 (mod p)

### 模运算与逆元

#### 模逆元
若 a·x ≡ 1 (mod m)，则 x 是 a 在模 m 下的逆元，记为 a^(-1)

##### 使用扩展欧几里得算法求逆元
```cpp
// 扩展欧几里得算法求 ax + by = gcd(a,b) 的一组解
tuple<int, int, int> extended_gcd(int a, int b) {
    if (b == 0) return {a, 1, 0};
    auto [d, x, y] = extended_gcd(b, a % b);
    return {d, y, x - (a / b) * y};
}

// 求 a 在模 m 下的逆元，要求 a 与 m 互质
int mod_inverse(int a, int m) {
    auto [g, x, y] = extended_gcd(a, m);
    if (g != 1) return -1;  // 逆元不存在
    return (x % m + m) % m; // 保证结果为正
}
```

##### 使用费马小定理求逆元（当 m 为质数时）
```cpp
// 当 m 是质数时，a^(m-2) 是 a 在模 m 下的逆元
int mod_inverse_fermat(int a, int m) {
    return fast_pow(a, m - 2, m);
}
```

#### 组合数取模
```cpp
// 使用逆元计算组合数取模
// 前置条件：MOD 是质数，且 n, k 较小
int combination_mod(int n, int k, int MOD) {
    if (k > n) return 0;
    if (k > n - k) k = n - k;
    
    long long res = 1;
    for (int i = 0; i < k; i++) {
        res = (res * (n - i)) % MOD;
        res = (res * mod_inverse_fermat(i + 1, MOD)) % MOD;
    }
    return res;
}
```

#### 线性求逆元
```cpp
// 线性求1到n的所有数的逆元
vector<int> inverse_all(int n, int p) {
    vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    }
    return inv;
}
```

### 中国剩余定理 (CRT)
解决形如 x ≡ a_i (mod m_i) 的一组同余方程

```cpp
// 中国剩余定理，解 x ≡ a[i] (mod m[i])
long long CRT(vector<int>& a, vector<int>& m) {
    int n = a.size();
    long long M = 1, ans = 0;
    
    for (int i = 0; i < n; i++) M *= m[i];
    
    for (int i = 0; i < n; i++) {
        long long Mi = M / m[i];
        long long inv = mod_inverse(Mi % m[i], m[i]);
        ans = (ans + (a[i] * Mi % M) * inv % M) % M;
    }
    
    return ans;
}
```

### 二次剩余
```cpp
// 平方根模质数p，p为形如4k+3的质数
int sqrt_mod(int n, int p) {
    n %= p;
    if (n == 0) return 0;
    if (p == 2) return n;
    if (fast_pow(n, (p - 1) / 2, p) != 1) return -1; // 不存在平方根
    
    if (p % 4 == 3) 
        return fast_pow(n, (p + 1) / 4, p);
        
    // 对于p=4k+1的情况需要使用Shanks-Tonelli算法
    // 略
}
```

## 常用算法

### 最大公约数和最小公倍数
```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
```

### 快速幂
```cpp
long long fast_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
```

### 素数筛法
```cpp
vector<bool> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
```

## 图算法

### 深度优先搜索 (DFS)
```cpp
void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}
```

### 广度优先搜索 (BFS)
```cpp
void bfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

### Dijkstra最短路径
```cpp
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (d > dist[node]) continue;
        
        for (auto& [neighbor, weight] : graph[node]) {
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}
```

## 动态规划模板

动态规划是解决具有重叠子问题和最优子结构的问题的算法。关键思想是将大问题分解为子问题，并存储子问题的解以避免重复计算。

### 背包问题

背包问题是动态规划中的经典问题，涉及从给定的物品集合中选择物品放入背包，以最大化总价值并满足重量限制。

#### 0-1背包
每个物品只能选择一次，要么选择要么不选择。

```cpp
// 0-1背包
// 返回最大价值
vector<int> knapsack01(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp;
}
```

#### 完全背包
每个物品可以选择无限次。

```cpp
// 完全背包
// 返回最大价值
vector<int> knapsackComplete(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int w = weights[i]; w <= capacity; w++) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp;
}
```

#### 多重背包
每个物品有指定的数量限制。

```cpp
// 多重背包
// 返回最大价值
int multipleKnapsack(vector<int>& weights, vector<int>& values, vector<int>& counts, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < n; i++) {
        // 二进制优化，将counts[i]个物品i分解为2^k形式
        int count = counts[i];
        for (int k = 1; count > 0; k <<= 1) {
            int amount = min(k, count);
            count -= amount;
            int weight = weights[i] * amount;
            int value = values[i] * amount;
            
            // 类似0-1背包处理这个新物品
            for (int w = capacity; w >= weight; w--) {
                dp[w] = max(dp[w], dp[w - weight] + value);
            }
        }
    }
    return dp[capacity];
}
```

#### 分组背包
物品分为若干组，每组最多选一件物品。

```cpp
// 分组背包
// groups[i]表示第i组的物品索引列表
int groupKnapsack(vector<int>& weights, vector<int>& values, vector<vector<int>>& groups, int capacity) {
    vector<int> dp(capacity + 1, 0);
    
    for (const auto& group : groups) {
        for (int w = capacity; w >= 0; w--) {
            for (int item : group) {
                if (w >= weights[item]) {
                    dp[w] = max(dp[w], dp[w - weights[item]] + values[item]);
                }
            }
        }
    }
    return dp[capacity];
}
```

### 线性DP

#### 最长公共子序列 (LCS)
寻找两个序列的最长公共子序列长度。

```cpp
// 最长公共子序列
int lcs(string& s1, string& s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
```

#### 最长上升子序列 (LIS)
寻找序列中最长的严格递增子序列长度。

```cpp
// 最长上升子序列 - O(n²)方法
int lis_n2(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    vector<int> dp(n, 1);  // dp[i]表示以nums[i]结尾的最长上升子序列长度
    int max_len = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }
    return max_len;
}

// 最长上升子序列 - O(nlogn)方法
int lis_nlogn(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    vector<int> tails;  // tails[i]表示长度为i+1的LIS的最小结尾值
    
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);  // 扩展LIS
        } else {
            *it = num;  // 优化已有LIS
        }
    }
    
    return tails.size();
}
```

#### 编辑距离
计算将一个字符串转换为另一个所需的最少操作次数（插入、删除、替换）。

```cpp
// 编辑距离
int editDistance(string& word1, string& word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    
    // 初始化边界
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j],      // 删除
                                   dp[i][j-1],       // 插入
                                   dp[i-1][j-1]});   // 替换
            }
        }
    }
    
    return dp[m][n];
}
```

### 区间DP

区间DP处理区间问题，通常按照区间长度从小到大计算。

#### 矩阵链乘法
确定矩阵乘法的最佳顺序以最小化计算量。

```cpp
// 矩阵链乘法
// dimensions[i-1]和dimensions[i]分别是第i个矩阵的行数和列数
int matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size() - 1;  // n个矩阵
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for (int len = 2; len <= n; len++) {  // 区间长度
        for (int i = 1; i <= n - len + 1; i++) {  // 区间起点
            int j = i + len - 1;  // 区间终点
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {  // 枚举分割点
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 
                              dimensions[i-1] * dimensions[k] * dimensions[j]);
            }
        }
    }
    
    return dp[1][n];
}
```

#### 石子合并
将n堆石子合并成一堆，每次合并两堆相邻的石子，求最小代价。

```cpp
// 石子合并
// stones[i]表示第i堆石子的数量
int mergeStones(vector<int>& stones) {
    int n = stones.size();
    vector<int> prefix(n+1, 0);  // 前缀和
    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + stones[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int len = 2; len <= n; len++) {  // 区间长度
        for (int i = 0; i <= n - len; i++) {  // 区间起点
            int j = i + len - 1;  // 区间终点
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {  // 枚举分割点
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
            // 合并整个区间的代价：区间内所有石子数量
            dp[i][j] += prefix[j+1] - prefix[i];
        }
    }
    
    return dp[0][n-1];
}
```

### 状态压缩DP

当问题状态集合较小时，可以使用二进制数表示状态，利用位运算进行状态转移。

#### 旅行商问题 (TSP)
找到访问所有城市并返回起点的最短路径。

```cpp
// 旅行商问题
// graph[i][j]表示城市i到j的距离
int tsp(vector<vector<int>>& graph) {
    int n = graph.size();
    int all_visited = (1 << n) - 1;  // 所有城市都被访问的状态
    
    // dp[mask][i]表示当前处于城市i，已经访问了mask中的城市的最短距离
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    dp[1][0] = 0;  // 初始状态：只访问了城市0
    
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;  // 城市i未被访问
            
            int prev_mask = mask ^ (1 << i);  // 去掉城市i
            if (prev_mask == 0) continue;  // 除了i没有访问其他城市
            
            for (int j = 0; j < n; j++) {
                if ((prev_mask & (1 << j)) == 0) continue;  // 城市j未在prev_mask中
                if (dp[prev_mask][j] != INT_MAX && graph[j][i] != INT_MAX) {
                    dp[mask][i] = min(dp[mask][i], dp[prev_mask][j] + graph[j][i]);
                }
            }
        }
    }
    
    // 从最后一个城市返回起点0
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (dp[all_visited][i] != INT_MAX && graph[i][0] != INT_MAX) {
            ans = min(ans, dp[all_visited][i] + graph[i][0]);
        }
    }
    
    return ans;
}
```

#### 集合覆盖问题
在集合中选择最少数量的子集，使它们的并集包含所有元素。

```cpp
// 集合覆盖问题
// sets[i]表示第i个集合覆盖的元素（用二进制位表示）
int setCover(vector<int>& sets, int universe) {
    int n = sets.size();
    vector<int> dp(1 << universe, INT_MAX / 2);  // dp[mask]表示覆盖mask所需的最少集合数
    dp[0] = 0;  // 覆盖空集不需要任何集合
    
    for (int mask = 0; mask < (1 << universe); mask++) {
        for (int i = 0; i < n; i++) {
            // 使用第i个集合后能覆盖的新状态
            int new_mask = mask | sets[i];
            dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
        }
    }
    
    return dp[(1 << universe) - 1];  // 覆盖所有元素
}
```

### 树形DP

在树结构上应用动态规划，通常使用DFS遍历树。

#### 树的最大独立集
选择树中最多的节点，使得没有两个节点相邻。

```cpp
// 树的最大独立集
// tree[i]表示节点i的邻居
pair<int, int> tree_independent_set(vector<vector<int>>& tree, int node, int parent) {
    int take = 1;  // 选择当前节点
    int not_take = 0;  // 不选择当前节点
    
    for (int child : tree[node]) {
        if (child == parent) continue;
        
        auto [child_take, child_not_take] = tree_independent_set(tree, child, node);
        take += child_not_take;  // 如果选择当前节点，则不能选择子节点
        not_take += max(child_take, child_not_take);  // 如果不选择当前节点，可以选择或不选择子节点
    }
    
    return {take, not_take};
}

int max_independent_set(vector<vector<int>>& tree) {
    auto [take, not_take] = tree_independent_set(tree, 0, -1);
    return max(take, not_take);
}
```

#### 树的直径
树中最长的路径长度。

```cpp
// 树的直径
// tree[i]表示节点i的邻居及权重
pair<int, int> tree_diameter(vector<vector<pair<int, int>>>& tree, int node, int parent) {
    int max_path = 0;  // 经过当前节点的最长路径
    int max_depth = 0;  // 以当前节点为根的最大深度
    
    // 找到最大和次大深度
    int max1 = 0, max2 = 0;
    for (auto [child, weight] : tree[node]) {
        if (child == parent) continue;
        
        auto [child_path, child_depth] = tree_diameter(tree, child, node);
        max_path = max(max_path, child_path);
        
        int depth = child_depth + weight;
        if (depth > max1) {
            max2 = max1;
            max1 = depth;
        } else if (depth > max2) {
            max2 = depth;
        }
    }
    
    max_path = max(max_path, max1 + max2);  // 更新经过当前节点的最长路径
    max_depth = max1;  // 以当前节点为根的最大深度
    
    return {max_path, max_depth};
}

int diameter(vector<vector<pair<int, int>>>& tree) {
    return tree_diameter(tree, 0, -1).first;
}
```

### 数位DP

用于计算满足特定数位条件的数字数量。通常从高位到低位进行处理。

```cpp
// 数位DP：计算[0,n]中数字d出现的次数
int countDigit(int n, int d) {
    if (n <= 0 || d < 0 || d > 9) return 0;
    
    int count = 0;
    int factor = 1;
    int high = n / 10, curr = n % 10, low = 0;
    
    while (high != 0 || curr != 0) {
        if (curr < d) {
            count += high * factor;
        } else if (curr == d) {
            count += high * factor + low + 1;
        } else {
            count += (high + 1) * factor;
        }
        
        low += curr * factor;
        curr = high % 10;
        high /= 10;
        factor *= 10;
    }
    
    return count;
}
```

### 概率DP

处理概率相关的问题，如期望值等。

```cpp
// 期望步数：从起点到终点的期望步数
// trans[i][j]表示状态i转移到状态j的概率
double expectedSteps(vector<vector<double>>& trans, int start, int end) {
    int n = trans.size();
    vector<double> expected(n, 0);
    
    for (int step = 0; step < 1000; step++) {  // 迭代求解
        vector<double> new_expected(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == end) continue;
            
            new_expected[i] = 1.0;  // 至少需要一步
            for (int j = 0; j < n; j++) {
                new_expected[i] += trans[i][j] * expected[j];
            }
        }
        expected = new_expected;
    }
    
    return expected[start];
}
```

## 倍增思想算法

倍增思想是通过预处理，将复杂度从O(n)降到O(logn)的一种算法思想。核心是利用二进制拆分，将问题转化为2的幂次的组合。

### 倍增求LCA（最近公共祖先）

最近公共祖先(Lowest Common Ancestor)问题是在树结构中寻找两个节点的最近公共祖先。使用倍增法可以将查询优化到O(logn)复杂度。

```cpp
// 倍增法求LCA

const int MAXN = 1e5 + 5;   // 最大节点数
const int LOGN = 20;        // log2(MAXN)，表示最大深度的二进制位数
vector<int> tree[MAXN];     // 存储树的邻接表
int depth[MAXN];            // 每个节点的深度
int fa[MAXN][LOGN];         // fa[i][j]表示节点i的2^j祖先

// DFS预处理每个节点的深度和父节点
void dfs(int u, int parent) {
    fa[u][0] = parent;
    depth[u] = (parent == -1) ? 0 : depth[parent] + 1;
    
    // 预处理倍增祖先
    for (int j = 1; j < LOGN; j++) {
        if (fa[u][j-1] != -1)
            fa[u][j] = fa[fa[u][j-1]][j-1];
        else
            fa[u][j] = -1;
    }
    
    for (int v : tree[u]) {
        if (v != parent) {
            dfs(v, u);
        }
    }
}

// 求两个节点的LCA
int lca(int u, int v) {
    // 保证u的深度不小于v
    if (depth[u] < depth[v]) swap(u, v);
    
    // 将u上升到与v相同的深度
    int diff = depth[u] - depth[v];
    for (int j = 0; j < LOGN; j++) {
        if (diff & (1 << j)) {
            u = fa[u][j];
        }
    }
    
    // 如果此时u和v相同，则v是u的祖先
    if (u == v) return u;
    
    // 一起向上跳转，直到找到LCA的直接子节点
    for (int j = LOGN - 1; j >= 0; j--) {
        if (fa[u][j] != fa[v][j]) {
            u = fa[u][j];
            v = fa[v][j];
        }
    }
    
    // 返回LCA
    return fa[u][0];
}

// 初始化LCA
void initLCA(int root, int n) {
    // 初始化fa数组
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < LOGN; j++) {
            fa[i][j] = -1;
        }
    }
    
    dfs(root, -1);
}
```

### 倍增求区间最值

使用倍增思想可以快速查询区间最大值或最小值。

```cpp
// 倍增求区间最大值
const int MAXN = 1e5 + 5;
const int LOGN = 20;
int arr[MAXN];             // 原始数组
int st_max[MAXN][LOGN];    // 稀疏表，st_max[i][j]表示从i开始长度为2^j的区间的最大值

// 预处理稀疏表
void buildSparseTable(int n) {
    // 初始化长度为1的区间
    for (int i = 0; i < n; i++) {
        st_max[i][0] = arr[i];
    }
    
    // 填充稀疏表
    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st_max[i][j] = max(st_max[i][j-1], st_max[i + (1 << (j-1))][j-1]);
        }
    }
}

// 查询区间[L, R]的最大值，0-indexed
int queryMax(int L, int R) {
    int k = 31 - __builtin_clz(R - L + 1); // 计算log2(R-L+1)
    return max(st_max[L][k], st_max[R - (1 << k) + 1][k]);
}
```

### 倍增求任意节点间最短路径

在树上求任意两点之间的距离。

```cpp
// 倍增求树上任意两点距离
const int MAXN = 1e5 + 5;
const int LOGN = 20;
vector<pair<int, int>> tree[MAXN]; // 带权边的树
int depth[MAXN];                    // 节点深度
int fa[MAXN][LOGN];                 // 祖先数组
long long dist[MAXN][LOGN];         // 到祖先的距离

void dfs(int u, int parent, long long d = 0) {
    depth[u] = (parent == -1) ? 0 : depth[parent] + 1;
    fa[u][0] = parent;
    dist[u][0] = d;
    
    for (int j = 1; j < LOGN; j++) {
        if (fa[u][j-1] != -1) {
            fa[u][j] = fa[fa[u][j-1]][j-1];
            dist[u][j] = dist[u][j-1] + dist[fa[u][j-1]][j-1];
        } else {
            fa[u][j] = -1;
            dist[u][j] = 0;
        }
    }
    
    for (auto [v, w] : tree[u]) {
        if (v != parent) {
            dfs(v, u, w);
        }
    }
}

// 计算树上两点间的距离
long long getDistance(int u, int v) {
    if (u == v) return 0;
    
    long long result = 0;
    
    // 保证u的深度不小于v
    if (depth[u] < depth[v]) swap(u, v);
    
    // u上升到与v相同的深度，累计距离
    int diff = depth[u] - depth[v];
    for (int j = 0; j < LOGN; j++) {
        if (diff & (1 << j)) {
            result += dist[u][j];
            u = fa[u][j];
        }
    }
    
    // 如果此时u和v相同，则已找到LCA
    if (u == v) return result;
    
    // 一起向上跳转，找到LCA的直接子节点
    for (int j = LOGN - 1; j >= 0; j--) {
        if (fa[u][j] != fa[v][j]) {
            result += dist[u][j] + dist[v][j];
            u = fa[u][j];
            v = fa[v][j];
        }
    }
    
    // 最后加上到LCA的距离
    result += dist[u][0] + dist[v][0];
    
    return result;
}
```

### 倍增求序列第k个不同数

使用倍增思想可以快速找到序列中的第k个不同数。

```cpp
// 倍增求序列第k个不同数
const int MAXN = 1e5 + 5;
const int LOGN = 20;
int arr[MAXN];              // 原始序列
int nextDiff[MAXN][LOGN];   // nextDiff[i][j]表示从位置i开始，第2^j个不同的数的位置

// 预处理nextDiff数组
void buildNextDiff(int n) {
    // 初始化第一个不同的位置
    set<int> seen;
    for (int i = n - 1; i >= 0; i--) {
        // 找到下一个不同的数的位置
        int next = n;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] != arr[i]) {
                next = j;
                break;
            }
        }
        nextDiff[i][0] = next;
    }
    
    // 填充倍增数组
    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i < n; i++) {
            if (nextDiff[i][j-1] < n) {
                nextDiff[i][j] = nextDiff[nextDiff[i][j-1]][j-1];
            } else {
                nextDiff[i][j] = n;
            }
        }
    }
}

// 查询从位置start开始第k个不同数的位置
int queryKthDiff(int start, int k, int n) {
    int pos = start;
    
    // 二进制分解k，跳转到对应位置
    for (int j = LOGN - 1; j >= 0; j--) {
        if (k & (1 << j)) {
            pos = nextDiff[pos][j];
            if (pos >= n) return -1; // 不存在第k个不同数
        }
    }
    
    return pos;
}
```

### 倍增优化RMQ (Range Minimum Query)

RMQ是指在给定数组中查询指定区间内的最小值。使用倍增可以O(1)时间查询。

```cpp
// 倍增优化RMQ
const int MAXN = 1e5 + 5;
const int LOGN = 20;
int arr[MAXN];             // 原始数组
int st_min[MAXN][LOGN];    // 稀疏表，st_min[i][j]表示从i开始长度为2^j的区间的最小值

// 预处理稀疏表
void buildSparseTable(int n) {
    // 初始化长度为1的区间
    for (int i = 0; i < n; i++) {
        st_min[i][0] = arr[i];
    }
    
    // 填充稀疏表
    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st_min[i][j] = min(st_min[i][j-1], st_min[i + (1 << (j-1))][j-1]);
        }
    }
}

// 查询区间[L, R]的最小值，0-indexed
int queryMin(int L, int R) {
    int k = 31 - __builtin_clz(R - L + 1); // 计算log2(R-L+1)
    return min(st_min[L][k], st_min[R - (1 << k) + 1][k]);
}
```

### 倍增解决翻转问题

处理数组或字符串的多次翻转操作，并能快速查询特定位置的元素。

```cpp
// 倍增解决多次翻转后的查询问题
const int MAXN = 1e5 + 5;
const int LOGN = 20;
int arr[MAXN];                // 原始数组
bool reverse_tag[MAXN];       // 标记区间是否被翻转
int nxt[MAXN][LOGN][2];       // nxt[i][j][0/1]表示位置i经过2^j步后的位置，0表示不翻转，1表示翻转

// 预处理nxt数组
void buildNext(int n) {
    // 初始化第一步
    for (int i = 0; i < n; i++) {
        nxt[i][0][0] = (i + 1) % n;       // 不翻转时的下一个位置
        nxt[i][0][1] = (n - 1 - i) % n;   // 翻转时的下一个位置
    }
    
    // 填充倍增数组
    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i < n; i++) {
            nxt[i][j][0] = nxt[nxt[i][j-1]][0][j-1][0];   // 不翻转的情况
            nxt[i][j][1] = nxt[nxt[i][j-1]][1][j-1][1];   // 翻转的情况
        }
    }
}

// 查询经过多次操作后位置pos的元素
int query(int pos, vector<pair<int, int>>& operations) {
    int curr_pos = pos;
    bool reversed = false;
    
    // 按照操作顺序处理
    for (auto [l, r] : operations) {
        if (l <= curr_pos && curr_pos <= r) {
            // 如果当前位置在翻转区间内
            curr_pos = l + (r - curr_pos);
            reversed = !reversed;
        }
    }
    
    return arr[curr_pos];
}
```

### 倍增求解幂函数

快速幂是一个经典的倍增算法，可以在O(logn)时间内计算a^n。

```cpp
// 快速幂
long long fastPow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}
```

## 矩阵算法

矩阵是解决线性代数问题及各种组合问题的强大工具。通过矩阵运算可以高效解决线性递推、计数和图论等问题。

### 矩阵基本运算

```cpp
// 矩阵类
struct Matrix {
    int n, m;  // n行m列
    vector<vector<long long>> mat;
    
    // 构造一个n行m列的矩阵
    Matrix(int n, int m) : n(n), m(m) {
        mat.resize(n, vector<long long>(m, 0));
    }
    
    // 构造单位矩阵
    static Matrix identity(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; i++) {
            res.mat[i][i] = 1;
        }
        return res;
    }
    
    // 矩阵加法
    Matrix operator + (const Matrix& other) const {
        Matrix res(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res.mat[i][j] = (mat[i][j] + other.mat[i][j]) % MOD;
            }
        }
        return res;
    }
    
    // 矩阵乘法
    Matrix operator * (const Matrix& other) const {
        int p = other.m;
        Matrix res(n, p);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < m; k++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j] % MOD) % MOD;
                }
            }
        }
        return res;
    }
};
```

### 矩阵快速幂

使用快速幂思想计算矩阵的幂，可以在O(n³logk)时间内计算A^k。

```cpp
// 矩阵快速幂
Matrix matrix_power(Matrix base, long long exp) {
    int n = base.n;
    Matrix res = Matrix::identity(n);
    
    while (exp > 0) {
        if (exp & 1) {
            res = res * base;
        }
        base = base * base;
        exp >>= 1;
    }
    
    return res;
}
```

### 应用一：求解线性递推关系

用矩阵快速幂解决形如 F(n) = a₁F(n-1) + a₂F(n-2) + ... + aₖF(n-k) 的线性递推关系。

```cpp
// 使用矩阵快速幂求解斐波那契数列第n项
int fibonacci(long long n) {
    if (n <= 1) return n;
    
    // 构造转移矩阵 [1 1; 1 0]
    Matrix base(2, 2);
    base.mat[0][0] = 1;
    base.mat[0][1] = 1;
    base.mat[1][0] = 1;
    base.mat[1][1] = 0;
    
    // 计算 base^(n-1)
    Matrix res = matrix_power(base, n - 1);
    
    // 结果为 res * [1; 0]
    return res.mat[0][0];
}

// 使用矩阵快速幂求解一般线性递推关系
// coefficients[i]表示a_{i+1}，init[i]表示F(i)
int linear_recurrence(const vector<int>& coefficients, const vector<int>& init, long long n) {
    int k = coefficients.size();
    if (n < k) return init[n];
    
    // 构造转移矩阵
    Matrix base(k, k);
    for (int i = 0; i < k - 1; i++) {
        base.mat[i][i+1] = 1;  // 下一个状态转移
    }
    for (int i = 0; i < k; i++) {
        base.mat[k-1][i] = coefficients[k-1-i];  // 最后一行填入系数
    }
    
    // 计算 base^(n-k+1)
    Matrix res = matrix_power(base, n - k + 1);
    
    // 计算结果
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans = (ans + res.mat[0][i] * init[k-1-i] % MOD) % MOD;
    }
    
    return ans;
}
```

### 应用二：求解图的路径计数问题

矩阵幂可以用来解决图中两点之间长度为k的路径数问题。

```cpp
// 计算图中两点之间长度为k的路径数
int count_paths(const vector<vector<int>>& graph, int start, int end, int k) {
    int n = graph.size();
    
    // 构造邻接矩阵
    Matrix adj(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj.mat[i][j] = graph[i][j];
        }
    }
    
    // 计算邻接矩阵的k次幂
    Matrix res = matrix_power(adj, k);
    
    // 返回从start到end的路径数
    return res.mat[start][end];
}
```

### 应用三：高斯消元解线性方程组

```cpp
// 高斯消元法求解线性方程组 Ax = b
// 返回是否有唯一解，如果有，解存储在 x 中
bool gauss(vector<vector<double>>& A, vector<double>& b, vector<double>& x) {
    int n = A.size();
    x.resize(n, 0);
    
    // 增广矩阵
    vector<vector<double>> aug(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = A[i][j];
        }
        aug[i][n] = b[i];
    }
    
    // 高斯消元
    for (int i = 0; i < n; i++) {
        // 寻找主元
        int max_row = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(aug[j][i]) > abs(aug[max_row][i])) {
                max_row = j;
            }
        }
        
        // 主元过小，可能没有唯一解
        if (abs(aug[max_row][i]) < 1e-9) {
            return false;
        }
        
        // 交换行
        if (max_row != i) {
            swap(aug[i], aug[max_row]);
        }
        
        // 消元
        for (int j = i + 1; j < n; j++) {
            double factor = aug[j][i] / aug[i][i];
            for (int k = i; k <= n; k++) {
                aug[j][k] -= aug[i][k] * factor;
            }
        }
    }
    
    // 回代
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += aug[i][j] * x[j];
        }
        x[i] = (aug[i][n] - sum) / aug[i][i];
    }
    
    return true;
}
```

### 应用四：矩阵树定理计算生成树个数

```cpp
// 使用矩阵树定理计算无向图的生成树个数
int count_spanning_trees(const vector<vector<int>>& graph) {
    int n = graph.size();
    
    // 构造拉普拉斯矩阵
    vector<vector<int>> laplacian(n, vector<int>(n, 0));
    
    // 对角线上是顶点的度
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] > 0) {  // 有边
                laplacian[i][i] += graph[i][j];
            }
        }
    }
    
    // 非对角线上是边的负权重
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] > 0) {  // 有边
                laplacian[i][j] = -graph[i][j];
            }
        }
    }
    
    // 去掉最后一行一列，计算代数余子式
    vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            submatrix[i][j] = laplacian[i][j];
        }
    }
    
    // 计算行列式（使用高斯消元法）
    double det = 1.0;
    for (int i = 0; i < n - 1; i++) {
        // 寻找主元
        int max_row = i;
        for (int j = i + 1; j < n - 1; j++) {
            if (abs(submatrix[j][i]) > abs(submatrix[max_row][i])) {
                max_row = j;
            }
        }
        
        if (max_row != i) {
            swap(submatrix[i], submatrix[max_row]);
            det = -det;  // 交换行，行列式变号
        }
        
        det *= submatrix[i][i];
        
        // 消元
        for (int j = i + 1; j < n - 1; j++) {
            double factor = submatrix[j][i] / submatrix[i][i];
            for (int k = i; k < n - 1; k++) {
                submatrix[j][k] -= submatrix[i][k] * factor;
            }
        }
    }
    
    return round(det);  // 四舍五入为整数
}
```

### 应用五：矩阵求逆

```cpp
// 矩阵求逆（高斯-约旦消元法）
Matrix inverse(const Matrix& A) {
    int n = A.n;
    if (A.n != A.m) {
        throw runtime_error("Matrix is not square");
    }
    
    // 构造增广矩阵 [A|I]
    Matrix aug(n, 2 * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug.mat[i][j] = A.mat[i][j];
        }
        aug.mat[i][i + n] = 1;  // 单位矩阵部分
    }
    
    // 高斯-约旦消元
    for (int i = 0; i < n; i++) {
        // 找主元
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(aug.mat[j][i]) > abs(aug.mat[pivot][i])) {
                pivot = j;
            }
        }
        
        if (aug.mat[pivot][i] == 0) {
            throw runtime_error("Matrix is singular");
        }
        
        // 交换行
        if (pivot != i) {
            swap(aug.mat[i], aug.mat[pivot]);
        }
        
        // 将主元归一化
        long long inv = fast_pow(aug.mat[i][i], MOD - 2, MOD);  // 求逆元
        for (int j = 0; j < 2 * n; j++) {
            aug.mat[i][j] = (aug.mat[i][j] * inv) % MOD;
        }
        
        // 消元
        for (int j = 0; j < n; j++) {
            if (j != i) {
                long long factor = aug.mat[j][i];
                for (int k = 0; k < 2 * n; k++) {
                    aug.mat[j][k] = (aug.mat[j][k] - factor * aug.mat[i][k] % MOD + MOD) % MOD;
                }
            }
        }
    }
    
    // 提取右半部分作为逆矩阵
    Matrix res(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res.mat[i][j] = aug.mat[i][j + n];
        }
    }
    
    return res;
}
```

### 应用六：常系数线性微分方程的求解

```cpp
// 使用矩阵指数解常系数线性微分方程
// 求解形如 y' = Ay 的方程，其中 A 是常系数矩阵
Matrix matrix_exponential(const Matrix& A, double t, int iterations = 20) {
    int n = A.n;
    Matrix result = Matrix::identity(n);
    Matrix term = Matrix::identity(n);
    double factorial = 1.0;
    
    for (int i = 1; i <= iterations; i++) {
        factorial *= i;
        term = term * A;  // A^i
        
        Matrix scaled_term = term;
        double power_t = pow(t, i);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                scaled_term.mat[r][c] = scaled_term.mat[r][c] * power_t / factorial;
            }
        }
        
        result = result + scaled_term;
    }
    
    return result;
}
```

## 常用数学公式

- 组合数: C(n,k) = n!/(k!(n-k)!)
- 排列数: P(n,k) = n!/(n-k)!
- 斐波那契数列: F(n) = F(n-1) + F(n-2)
- 平方和: ∑i² = n(n+1)(2n+1)/6
- 等差数列和: ∑i = n(n+1)/2