#include<vector>
using namespace std;

// https://leetcode.cn/problems/combinations/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> v;
    void backtracking(int begin, int end, int k){
        if(v.size() == k){
            result.push_back(v);
            return;
        }
        for(int i = begin; i <= end; i++){
            v.push_back(i);
            backtracking(i+1, end, k);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(1,n,k);  
        return result;
    }
};