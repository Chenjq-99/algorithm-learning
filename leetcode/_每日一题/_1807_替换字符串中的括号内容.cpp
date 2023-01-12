#include<vector>
#include<unordered_map>
using namespace std;
// https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string/
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto &k : knowledge) {
            mp[k[0]] = k[1];
        }
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(') res += s[i];
            else {
                string t;
                while (s[++i] != ')') {
                    t += s[i];
                }
                res += mp.count(t) ? mp[t] : "?";
            }
        }
        return res;
    }
};