#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// https://leetcode.cn/problems/course-schedule-iv/

class Solution {
private:
    void Floyd(vector<vector<int>>&isReachable, int n)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(isReachable[i][k] && isReachable[k][j]){
                    isReachable[i][j] = 1;
                }
            }
        }
    }
}
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> isReachable(numCourses,vector<int>(numCourses));       
        for(auto prerequisite : prerequisites){
            isReachable[prerequisite[0]][prerequisite[1]] = 1;
        }
        Floyd(isReachable, numCourses);
        vector<bool> result;
        for(auto querie : queries){
            if(isReachable[querie[0]][querie[1]]) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};