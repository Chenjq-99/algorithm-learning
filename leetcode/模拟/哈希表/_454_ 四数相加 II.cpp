#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/4sum-ii/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> record;
        int res = 0;
        for(int a : nums1){
            for(int b : nums2){
                record[a+b]++;
            }
        }
        for(int c : nums3){
            for(int d : nums4){
                if(record.find(-(c+d)) != record.end()) res += record[-(c+d)];
            }
        }
        return res;
    }
};

// 暴力循环的时间复杂度为O(n^4)
// 利用hash map 将前两个数组的和以及出现的次数进行记录
// 对后两个数组进行双重循环，看map中是否有-(a+b) 以及出现的次数
// 将O(n^4)转为2*O(n^2)


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if(m < n) return {};
        vector<int> hashTable(26);
        for(auto ch : p) ++hashTable[ch - 'a'];
        vector<int> ret;
        for(int l = 0, r = 0; r < m; ++r) {
            --hashTable[s[r] - 'a'];
            while(hashTable[s[r] - 'a'] < 0) {
                ++hashTable[s[l] - 'a'];
                ++l;
            }
            if(r - l + 1 == n) ret.push_back(l);
        }
        return ret;
    }
};