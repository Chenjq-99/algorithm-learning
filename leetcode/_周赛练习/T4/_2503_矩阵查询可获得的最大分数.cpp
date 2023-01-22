#include<vector>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<queue>
using namespace std;

class Solution {
private:
    vector<int> p;
    vector<int> size;
    int find(int x) {
        return x == p[x] ? p[x] : p[x] = find(p[x]);
    }
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            p[px] = py;
            size[py] += size[px];
        }
    }
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        // 抽象成图论
        // 答案就是包含[0, 0]的连通块大小
        // 连通块需要满足条件：点权 < q
        // 点权处理起来比较麻烦，可以转换成边权，再用并查集合并
        
        // 怎么转换成边权？
        // 把两个点连起来需要满足， 两个点 < q
        // 可以让边权等于 两个点权的最大值

        // 边权排序
        // 询问排序
        // 双指针遍历询问和边权
        // 每次把 < q 的边的两点合并
        // 答案就是包含左上角的连通块size

        // 方法一 并查集
        int m = grid.size(), n = grid[0].size(), mn = m * n, k = queries.size();
        p = vector<int>(mn);
        iota(p.begin(), p.end(), 0);
        size = vector<int>(mn, 1);
        auto getIdx = [&](const int& x, const int& y) {return x * n + y;};
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) edges.emplace_back(max(grid[i][j],grid[i-1][j]), getIdx(i,j), getIdx(i-1,j));
                if (j > 0) edges.emplace_back(max(grid[i][j],grid[i][j-1]), getIdx(i,j), getIdx(i,j-1));
            }
        }
        // 对边权排序
        sort(edges.begin(), edges.end());
        vector<int> ans(k);
        int id[k];
        iota(id, id + k, 0);
        sort(id, id + k, [&](int i, int j) { return queries[i] < queries[j]; });
        int j = 0;
        for (int i : id) {
            int q = queries[i];
            while (j < edges.size()) {
                auto [w, a, b] = edges[j];
                if (w < q) {
                    j++;
                    unite(a, b);
                } else break;
            }
            if (grid[0][0] < q) ans[i] = size[find(0)];
        }
        return ans;
    }
};

class Solution {
private:
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        // 方法二 ： 优先级队列
        // 初始把 {grid[0][0], 0, 0} 放入队列中
        // 遍历排序后的询问，再套一个while循环
        // 不断取队头元素，直至队列为空，或队头 >= q;
        //     循环内部，向四周扩展，把扩展后的格子的值和坐标加入队列中
        //     统计循环次数 或者 < q 的值的个数cnt
        // 循环结束之后，cnt就是答案
        int m = grid.size(), n = grid[0].size(), k = queries.size();
        vector<int> ans(k);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        grid[0][0] = 0;
        int cnt = 0;
        int id[k];
        iota(id, id + k, 0);
        sort(id, id + k, [&](int i, int j) { return queries[i] < queries[j]; });
        for (auto& i : id) {
            int q = queries[i];
            while (!pq.empty() && get<0>(pq.top()) < q) {
                cnt++;
                auto [_, x, y] = pq.top();
                pq.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y +d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny]) {
                        pq.emplace(grid[nx][ny], nx, ny);
                        grid[nx][ny] = 0;
                    }
                }
            }
            ans[i] = cnt;
        }
        return ans;

    }
};

