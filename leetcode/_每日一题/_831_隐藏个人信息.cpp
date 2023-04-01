// https://leetcode.cn/problems/masking-personal-information/
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string maskPII(string s) {
        string ans = "";
        int idx = s.find('@');
        if (idx != string::npos) {
            transform(s.begin(),s.end(),s.begin(),::tolower);
            ans =  s.substr(0, 1) + "*****" + s.substr(idx - 1);
        } else {
            vector<string> pre = {"", "+*-", "+**-", "+***-"};
            int cnt = count_if(s.begin(), s.end(), [&](auto &ch){return isdigit(ch);});
            ans = pre[cnt - 10] + "***-***-";
            string tmp = "";
            for (int i = s.size() - 1; i >= 0; i--) {
                if (isdigit(s[i])) tmp += s[i];
                if (tmp.size() == 4) break;
            }
            ans += string(tmp.rbegin(), tmp.rend());
        }
        return ans;
    }
};    