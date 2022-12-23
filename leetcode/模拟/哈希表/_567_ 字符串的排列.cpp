#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/permutation-in-string/
// 与438题一模一样
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> record(26);
        for(char c : s1) record[c - 'a']++;
        int l = 0, r = 0;
        while(r < s2.length()){
            record[s2[r] - 'a']--;
            while(record[s2[r] - 'a'] < 0){
                record[s2[l] - 'a']++;
                l++;
            }
            if(r - l + 1 == s1.length()) return true;
            r++;
        }
        return false;
    }
};
