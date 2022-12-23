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

// ��hash map��¼ s �и�����ĸ���ֵĴ���
// ���� t ���ж���
// ��� t �� s ����ĸ��λ��,��ô map ������value��Ϊ0