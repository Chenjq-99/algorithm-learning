#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/min-cost-to-connect-all-points/
class Solution {
private:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;
        int n;
        int setCount; // 当前连通分量数目
        
    public:
        UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }
        
        void unite(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py) return;
            if (size[px] < size[py]) swap(px, py);
            parent[py] = px;
            size[px] += size[py];
            --setCount;
            return;
        }
        
        bool same(int x, int y) {
            int px = find(x);
            int py = find(y);
            return px == py;
        }
    };
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        UnionFind uf(source.size());
        for(auto allowedSwap : allowedSwaps){
            uf.unite(allowedSwap[0],allowedSwap[1]);
        }
        unordered_map<int,unordered_map<int,int>> record;
        for(int i = 0; i < source.size(); i++){
            record[uf.find(i)][source[i]]++;
        }
        int res = 0;
        for(int i = 0; i < source.size(); i++){
            if(record[uf.find(i)][target[i]] <= 0) res++;
            else record[uf.find(i)][target[i]]--;
        }
        return res;
    }
};