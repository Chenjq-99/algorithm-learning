#include<string>
#include<vector>
using namespace std;
// https://leetcode.cn/problems/check-distances-between-same-letters/
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for (int i = 0; i < s.size(); i++) 
            for (int j = i + 1; j < s.size(); j++) 
                if (s[i] == s[j] && distance[s[i] - 'a'] != j - i -1) 
                    return false;
        return true;
    }
};