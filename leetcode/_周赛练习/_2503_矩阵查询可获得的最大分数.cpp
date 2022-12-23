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
        // �����ͼ��
        // �𰸾��ǰ���[0, 0]����ͨ���С
        // ��ͨ����Ҫ������������Ȩ < q
        // ��Ȩ���������Ƚ��鷳������ת���ɱ�Ȩ�����ò��鼯�ϲ�
        
        // ��ôת���ɱ�Ȩ��
        // ����������������Ҫ���㣬 ������ < q
        // �����ñ�Ȩ���� ������Ȩ�����ֵ

        // ��Ȩ����
        // ѯ������
        // ˫ָ�����ѯ�ʺͱ�Ȩ
        // ÿ�ΰ� < q �ıߵ�����ϲ�
        // �𰸾��ǰ������Ͻǵ���ͨ��size

        // ����һ ���鼯
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
        // �Ա�Ȩ����
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
        // ������ �� ���ȼ�����
        // ��ʼ�� {grid[0][0], 0, 0} ���������
        // ����������ѯ�ʣ�����һ��whileѭ��
        // ����ȡ��ͷԪ�أ�ֱ������Ϊ�գ����ͷ >= q;
        //     ѭ���ڲ�����������չ������չ��ĸ��ӵ�ֵ��������������
        //     ͳ��ѭ������ ���� < q ��ֵ�ĸ���cnt
        // ѭ������֮��cnt���Ǵ�
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

