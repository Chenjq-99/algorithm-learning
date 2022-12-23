#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> outEdges(numCourses);
        vector<int> inDegrees(numCourses);
        queue<int> queue;
        for(vector<int> ele : prerequisites){
            outEdges[ele[1]].push_back(ele[0]);
            inDegrees[ele[0]]++;
        }
        // 初始化将入度为0的放入队列
        for(int i = 0; i < numCourses; i++){
            if(inDegrees[i] == 0) queue.push(i);
        }
        while(!queue.empty()){
            int course = queue.front();
            queue.pop();
            res.push_back(course);
            if(outEdges[course].size() == 0) continue;
            for(int i : outEdges[course]){
                inDegrees[i]--;
                if(inDegrees[i] == 0){
                    queue.push(i);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};