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
// ��ʼ��p���ַ�����Ȼ��ά������ÿ��Ԫ�ز�С��0�� 
// ��ʼ���һ������ڣ���ȥ����Ӧ�ַ���
// ���Ƶ��С��0���������߽�ֱ��Ƶ�ʲ���С��0��
    // record[s[r] - 'a'] < 0 ˵��s[r]��P��û�У����߳����˸��ַ���p�е�����
    // �����s[r]��P��û�У����ʱ���һֱl++,ֱ��l����r
    // �����˸��ַ���p�е�����, ��һֱl++ֱ���³�һ��s[r]
// ���ڳ�����p����һ��ʱ���������