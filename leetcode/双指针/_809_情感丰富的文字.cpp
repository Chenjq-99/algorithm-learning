#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/expressive-words/description/
class Solution {
public:
#if 0
// 计数， 不太好
    int expressiveWords(string s, vector<string>& words) {
        vector<int> count1;
        string t1 = "";
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s[i] != s[i-1]) {
                t1 += s[i];
                count1.push_back(0);
            }
            count1[count1.size() - 1]++;
        }
        auto func = [&](vector<int>& count2){
            int n = t1.length();
            for (int i = 0; i < n; i++) {
                if (count1[i] == count2[i]) continue;
                else if (count1[i] < count2[i]) return 0;
                else {
                    if (count1[i] >= 3) continue;
                    else return 0;
                }
            }
            return 1;
        };

        int res = 0;
        for (auto& word : words) {
            vector<int> count2;
            string t2 = "";
            for (int i = 0; i < word.length(); i++) {
                if (i == 0 ||  word[i] != word[i-1]) {
                    t2 += word[i];
                    count2.push_back(0);
                }
                count2[count2.size() - 1]++;
            }
            if (t1 != t2) continue;
            else {
                res += func(count2);
            }
        }
        return res;
    }
#endif
// 双指针
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for (string word : words) {
            if (check(s, word)) res++;
        } 
        return res;
    }
    
private:
    bool check(string s, string word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] != word[j]) return false; 
            
            char c = s[i];
            
            int cnts = 0;
            while (i < s.size() && s[i] == c) {
                i++; 
                cnts++;
            }
            
            int cntw = 0;
            while (j < word.size() && word[j] == c) {
                j++; 
                cntw++;
            }
            
            if (cnts < cntw) return false;
            if (cnts > cntw && cnts < 3) return false; 
        }
        return i == s.size() && j == word.size();
    }
};