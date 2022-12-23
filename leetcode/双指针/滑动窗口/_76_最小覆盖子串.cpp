#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> count;

        int left = 0, min_left = 0, cnt = 0, min_size = s.size() + 1;

        for(int i = 0; i < t.size(); i++){
            count[t[i]]++;
        }

        unordered_map<char,int> copy = count;
        
        for(int right = 0; right < s.size(); right++){
            if(copy[s[right]] > 0){// ���ַ���t�д���

                if(--count[s[right]] >= 0){//ֻҪ����ַ���t�оͼ�һ
                    cnt++; // �ҵ����ַ�������һ
                }
                while(cnt == t.size()){
                    // l �� r ������ȫ�� t ���ַ�
                    if(right - left + 1 < min_size){// ��֮ǰ��¼��ҪС ���½��
                        min_left =  left; // ��¼�������µ���߽�
                        min_size = right - left + 1; // �������´��ڴ�С
                    }
                    // ׼���ͷ���߽�
                    if(copy[s[left]] > 0 && ++count[s[left]] > 0){// Ҫ�ͷŵ��ַ������У��� l ��  r û�и���ĸ��ַ� 
                        cnt--; // left��Ӧ���ַ���t�У��ͷź��ҵ����ַ�������һ
                    }
                    left++;
                }
            }
            
        }
        return min_size > s.size() ? "" : s.substr(min_left,min_size);

    }
};