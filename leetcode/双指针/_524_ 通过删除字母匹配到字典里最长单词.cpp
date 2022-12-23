#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for(int i = 0; i < dictionary.size(); i++){
            string record = "";
            int j1 = 0;
            for(int j2 = 0; j2 < s.size(); j2++){
                if(dictionary[i][j1] == s[j2]){
                    record += s[j2];
                    j1++;
                }
            }
            if(j1 == dictionary[i].size()){
                if(res.size() > record.size()){}
                else if(res.size() < record.size()) res = record;
                else res = res < record ? res : record;
            }
        }
        return res;
    }
};