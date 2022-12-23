#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26]= {0};
        for(char ele : magazine){
            record[ele-'a']++;
        }
        for(char ele : ransomNote){
            record[ele-'a']--;
            if(record[ele-'a'] < 0) return false;  
        }
        return true;
    }
};
