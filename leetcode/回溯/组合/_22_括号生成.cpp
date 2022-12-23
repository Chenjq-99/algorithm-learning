#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/generate-parentheses/description/
class Solution {
private:
    vector<string> result;
    string s = "(";
    char choices[2] = {'(',')'};
    void backtracking(int n, int left, int right){
        if(right > left) return;
        if(left == n && right == n){
            result.push_back(s);
            return;
        }
        for(int i = 0; i < 2; i++){
            if(i == 0 && left < n){
                s += choices[0];
                backtracking(n,left + 1,right);
                s.pop_back();
            }
            if(i == 1 && right < n){
                s += choices[1];
                backtracking(n,left,right + 1);
                s.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        backtracking(n, 1, 0);
        return result;
    }
};