#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/flower-planting-with-no-adjacent/
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int,vector<int>> edges;
        for(auto path : paths){
            edges[path[0] - 1].push_back(path[1] - 1);
            edges[path[1] - 1].push_back(path[0] - 1);
        }
        vector<int> answer(n);
        for(int i = 0; i < n; i++){
            vector<int> color(5);
            for(auto k : edges[i]){
                color[answer[k]] = 1;
            }
            for(int j = 1; j <= 4; j++){
                if(color[j] == 0){
                    answer[i] = j;
                    break;
                }
            }
        }
        return answer;
    }
};

