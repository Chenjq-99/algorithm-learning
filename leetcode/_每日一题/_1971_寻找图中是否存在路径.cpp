#include<vector>
#include<numeric>
using namespace std;

// https://leetcode.cn/problems/find-if-path-exists-in-graph/
class Solution {
private:
    vector<int> p;
    int find(int x) {
        return x == p[x] ? p[x] : p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            p[px] = py;
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        for (auto& e : edges) {
            merge(e[0],e[1]);
        }
        return same(source,destination);
    }
};