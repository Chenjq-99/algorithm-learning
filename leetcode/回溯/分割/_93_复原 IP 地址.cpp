#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/restore-ip-addresses/description/
class Solution {
private:
    vector<string> result;
    string s1;
    bool isValid(string& s2, int dotNum){
        if(dotNum >= 4) return false;
        if(s2.length() != 1 && s2[0] == '0') return false;
        int num = stoi(s2);
        if(num < 0 || num > 255) return false;
        return true;
    }
    void backtracking(int begin, string& s, int dotNum){
        if(begin == s.length() && dotNum == 4){
            result.push_back(s1);
            (result.end() - 1) -> pop_back();
            return;
        }
        string s2;
        for(int i = begin; i < s.length(); i++){
            s2 += s[i];
            if(isValid(s2, dotNum)){
                s1 += s2;
                s1 += '.';
                dotNum++;
                backtracking(i + 1, s, dotNum);
                dotNum--;
                s1.erase(s1.length() - s2.length() - 1, s2.length() + 1);
            }else{
                return;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(0, s, 0);
        return result;
    }
};
