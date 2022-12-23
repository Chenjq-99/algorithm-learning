#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/find-all-anagrams-in-a-string/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.length() < p.length()) return res;
        vector<int> record(26);
        for(char c : p) record[c - 'a']++;
        int l = 0, r = 0;
        while(r < s.length()){
            record[s[r] - 'a']--;
            while(record[s[r] - 'a'] < 0){ 
                record[s[l] - 'a']++;
                l++;
            }
            if(r - l + 1 == p.length()) res.push_back(l);
            r++;
        }
        return res;
    }
};
// 初始化p的字符数组然后维护数组每个元素不小于0。 
// 开始向右滑动窗口，减去并相应字符，
// 如果频率小于0就收缩左侧边界直到频率不再小于0。
    // record[s[r] - 'a'] < 0 说明s[r]在P中没有，或者超过了该字符在p中的数量
    // 如果是s[r]在P中没有，这个时候会一直l++,直到l跟上r
    // 超过了该字符在p中的数量, 会一直l++直到吐出一个s[r]
// 窗口长度与p长度一致时达成条件。