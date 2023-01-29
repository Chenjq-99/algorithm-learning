#include<string>
using namespace std;
// https://leetcode.cn/problems/count-asterisks/
class Solution {
public:
    int countAsterisks(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') res++;
            if (s[i] == '|') {
                i++;
                while (s[i] != '|') i++;
            }
        }
        return res;
    }
};
