#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> record;
        for(char ele : s){
            record[ele]++;
        }
        for(char ele : t){
            record[ele]--;
        }
        for(auto ele : record){
            if(ele.second != 0) return false;
        }
        return true;
    }
};

// 用hash map记录 s 中各个字母出现的次数
// 遍历 t 进行对消
// 如果 t 是 s 的字母异位词,那么 map 的所有value都为0