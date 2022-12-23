#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode.cn/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(),nums1.end());
        set<int> res;
        for(int ele : nums2){
            if(s1.find(ele) != s1.end()){
                res.insert(ele);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};