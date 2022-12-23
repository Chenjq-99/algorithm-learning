#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<numeric>
using namespace std;

// https://leetcode.cn/problems/accounts-merge/
class Solution {
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    int setCount; // ��ǰ��ͨ������Ŀ
    
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> email2Name;
        unordered_map<string,int> email2Index;
        int k = 0;
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                email2Name[accounts[i][j]] = accounts[i][0];
                if(email2Index.find(accounts[i][j]) == email2Index.end()){// �Ѿ�ӳ����Ĳ�����ӳ��
                    email2Index[accounts[i][j]] = k++;// ���˻�ӳ�������
                }
            }
        }
        UnionFind uf(email2Index.size());
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                uf.unite(email2Index[accounts[i][1]],email2Index[accounts[i][j]]); // ��ͬһ�����µ��˻��ϲ�
            }
        }
        unordered_set<int> roots;
        for(auto pair : email2Index){ // ͳ�Ʋ�ͬ���ϵĸ�
            roots.insert(uf.find(pair.second));
        }
        vector<vector<string>> results;
        for(int root : roots){ // �Բ�ͬ�ļ��Ͻ����ռ�
            vector<string> result;
            for(auto pair : email2Index){
                if(uf.same(pair.second,root)) result.push_back(pair.first);
            }
            sort(result.begin(),result.end()); // ����
            result.insert(result.begin(),email2Name[result[0]]); //�����Ʋ嵽ǰ��
            results.push_back(result);
        }
        return results;
    }
};