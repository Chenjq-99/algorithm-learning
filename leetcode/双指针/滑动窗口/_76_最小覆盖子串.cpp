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
            if(copy[s[right]] > 0){// 该字符在t中存在

                if(--count[s[right]] >= 0){//只要这个字符在t中就减一
                    cnt++; // 找到的字符计数加一
                }
                while(cnt == t.size()){
                    // l 到 r 包含了全部 t 中字符
                    if(right - left + 1 < min_size){// 比之前记录的要小 跟新结果
                        min_left =  left; // 记录最短情况下的左边界
                        min_size = right - left + 1; // 更新最新窗口大小
                    }
                    // 准备释放左边界
                    if(copy[s[left]] > 0 && ++count[s[left]] > 0){// 要释放的字符在他中，且 l 到  r 没有更多的该字符 
                        cnt--; // left对应的字符在t中，释放后找到的字符计数减一
                    }
                    left++;
                }
            }
            
        }
        return min_size > s.size() ? "" : s.substr(min_left,min_size);

    }
};