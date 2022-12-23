#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/keys-and-rooms/
class Solution {
public:
    int num;
    vector<bool> searched;
    void dfs(int begin, vector<vector<int>>& rooms){
        searched[begin] = true;
        num++;
        for(int next : rooms[begin]){
        if(!searched[next]) dfs(next, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        num = 0;
        searched.resize(n);
        dfs(0, rooms);
        return num == n;
    }
};


