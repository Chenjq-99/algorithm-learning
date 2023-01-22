#include<string>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/apply-bitwise-operations-to-make-strings-equal/
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        return (find(s.begin(), s.end(), '1') != s.end()) == 
               (find(target.begin(), target.end(), '1') != target.end());
    }
};