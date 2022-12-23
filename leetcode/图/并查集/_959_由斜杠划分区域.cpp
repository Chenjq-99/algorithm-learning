#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/regions-cut-by-slashes/
class Solution {
private:
    int n = 1000;
    int parents[1000];
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
    int regionsBySlashes(vector<string>& grid) {
        init();
        int ans = 1;
        int m = grid.size();
        set<int> edge;
        for(int i = 0; i < (m+1)*(m+1); i++){
            if(i / (m+1) == 0 || i / (m+1) == m || i % (m+1) == 0 || i % (m+1) == m){
                edge.insert(i);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                int k = i * (m + 1) + j;
                if(grid[i][j] == '/'){
                    int a = k + 1;
                    int b = k + m + 1;
                    if(same(a,b)) ans++;
                    join(a,b);
                }else if(grid[i][j] == '\\'){
                    int a = k ;
                    int b = k + m + 2;
                    if(same(a,b)) ans++;
                    join(a,b);
                }
            }
        }
        unordered_map<int,int> map;
        for(int num : edge){
            map[find(num)]++;
        }
        for(auto pair : map){
            ans += pair.second - 1;
        }
        return ans;
    }
};