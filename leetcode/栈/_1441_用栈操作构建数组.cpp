#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/build-an-array-with-stack-operations/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index = 0;
        vector<string> res;
        for(int i = 1; i <= target[target.size()-1]; i++){
            if(i != target[index]){
                res.push_back("Push");
                res.push_back("Pop");
            }else{
                res.push_back("Push");
                index++;
            }
        }
        return res;
    }
};