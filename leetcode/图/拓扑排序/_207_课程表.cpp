#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses);
        vector<vector<int>> toVertices(numCourses);
        queue<int> queue;
        for(vector<int> v : prerequisites){
            inDegrees[v[1]]++;
            toVertices[v[0]].push_back(v[1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(inDegrees[i] == 0) queue.push(i);
        }
        int count = 0;
        while(!queue.empty()){
            int vertex = queue.front();
            queue.pop();
            count++;
            for(int next : toVertices[vertex]){
                if(--inDegrees[next] == 0) queue.push(next);
            }
        }
        return count == numCourses ? true : false;
    }
};