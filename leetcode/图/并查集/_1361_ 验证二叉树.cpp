#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// https://leetcode.cn/problems/validate-binary-tree-nodes/
class Solution {
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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        UnionFind uf(n);
        vector<bool> isChild(n,false);
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                if(uf.same(i,leftChild[i]) || isChild[leftChild[i]]) return false;
                uf.unite(i,leftChild[i]);
                isChild[leftChild[i]] = true;
            }
            if(rightChild[i] != -1){
                if(uf.same(i,rightChild[i]) || isChild[rightChild[i]]) return false;
                uf.unite(i,rightChild[i]);
                isChild[rightChild[i]] = true;
            }
        }
        return uf.setCount == 1;
    }
};