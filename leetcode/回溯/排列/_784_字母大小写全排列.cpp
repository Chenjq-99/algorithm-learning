#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/letter-case-permutation/description/
class Solution {
private:
    vector<string> result;
    void backtracking(string s, int startIndex){
        result.push_back(s);
        for(int i = startIndex; i < s.length(); i++){
            if(s[i] <= 'Z' && s[i] >= 'A'){
                s[i] = s[i] + 32;
                backtracking(s, i + 1);
                s[i] = s[i] - 32;
            } else if(s[i] <= 'z' && s[i] >= 'a'){
                s[i] = s[i] - 32;
                backtracking(s, i + 1);
                s[i] = s[i] + 32;
            }
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        backtracking(s,0);
        return result;
    }
};