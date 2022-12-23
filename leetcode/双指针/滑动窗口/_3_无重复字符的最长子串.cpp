#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int i = 0;
        int res = 0;
        for(int j =0; j < s.size(); j++){
            map[s[j]]++;
            while(map[s[j]] > 1){
                map[s[i]]--;
                i++;
            }
            res = res > j - i + 1 ? res : j - i + 1;
        }
        return res;
    }
};