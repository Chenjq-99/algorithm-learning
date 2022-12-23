#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// https://leetcode.cn/problems/number-of-provinces/
class Solution {
private:
    int n = 40005; // �ڵ�����
    int father[40005];
    // ���鼯��ʼ��
    void init() {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }
    // ���鼯��Ѱ���Ĺ���
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // ��v->u �����߼��벢�鼯
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        init();
        int cityNums = isConnected.size();
        for(int i = 0; i < cityNums; i++){
            for(int j = i+1; j < cityNums; j++){
                if(isConnected[i][j] == 1) join(i,j);
            }
        }
        unordered_set<int> roots;
        for(int i =0; i < cityNums; i++){
            roots.insert(find(i));
        }
        return roots.size();
    }
};