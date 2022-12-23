#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// https://leetcode.cn/problems/course-schedule-iv/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        int isReachable[100][100] = {{0}};
        int inDegrees[100] = {0};
        for(auto prerequisite : prerequisites){
            isReachable[prerequisite[0]][prerequisite[1]] = 1;
            inDegrees[prerequisite[1]]++;
        }
        queue<int> queue;
        for(int i = 0; i < n; i++){
            if(inDegrees[i] == 0) queue.push(i);
        }
        while(!queue.empty()){
            int num = queue.front();
            queue.pop();
            for(int i = 0; i < n; i++){
                if(isReachable[num][i]){
                    for(int j = 0; j < n; j++){
                        if(isReachable[j][num]){ // ������Ҫע��һ������num���ϼ�����num�ϼ����¼���ͨ ����������num�¼����¼� ��num������ͨ
                            isReachable[j][i] = 1;
                        }
                    }
                   if(--inDegrees[i] == 0) queue.push(i);
                }
            }
        }
        vector<bool> result;
        for(auto querie : queries){
            if(isReachable[querie[0]][querie[1]]) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};