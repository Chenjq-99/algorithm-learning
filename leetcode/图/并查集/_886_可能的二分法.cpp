#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// https://leetcode.cn/problems/possible-bipartition/

class Solution {
    private:
    int n = 2005;
    int parents[2005];
    void init(){
        for(int i = 0; i < n; i++){
            parents[i] = i;
        }
    }
    int find(int i){
        return parents[i] == i ? i : find(parents[i]);
    }
    void join(int i, int j){
        int p1 = find(i);
        int p2 = find(j);
        if(p1 == p2) return;
        parents[p1] = p2;
    }
    bool same(int i, int j){
        return find(i) == find(j);
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(dislikes.size() == 0) return true;
        init();
        unordered_map<int,vector<int>> record;
        for(vector<int> dislike : dislikes){
            record[dislike[0]].push_back(dislike[1]);
            record[dislike[1]].push_back(dislike[0]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < record[i].size(); j++){
                join(record[i][0],record[i][j]);
                if(same(i,record[i][j])) return false;
            }
        }       
        return true;
    }
};