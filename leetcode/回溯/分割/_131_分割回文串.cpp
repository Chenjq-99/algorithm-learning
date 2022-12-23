#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/palindrome-partitioning/description/
class Solution {
private:
    vector<vector<string>> result;
    vector<string> v;
    bool isPalindrome(string s1){
        int left = 0;
        int right = s1.length() - 1;
        while(left <= right){
            if(s1[left] != s1[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void backtracking(int begin, string& s){
        if(begin == s.length()){
            result.push_back(v);
            return;
        }
        string s1 = "";
        for(int i = begin; i < s.length(); i++){
            s1 += s[i];
            if(s[begin] == s[i] && isPalindrome(s1)){
                v.push_back(s1);
                backtracking(i + 1, s);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(0, s);
        return result;
    }
};