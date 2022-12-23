#include<vector>
#include<queue>
#include<string>
using namespace std;

// https://leetcode.cn/problems/number-of-matching-subsequences/description/
class Solution {
public:
#if 0
    // 二分法
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> record(26);
        for (int i = 0 ; i < s.length(); i++) {
            record[s[i] - 'a'].push_back(i);
        }
        int res = words.size();
        for (auto& word : words) {
            if (word.size() > s.length()) {
                res--;
                continue;
            }
            int index = -1;
            for (auto& c :word) {
                vector<int>& v = record[c - 'a'];
                auto it =  upper_bound(v.begin(), v.end(), index);
                if (it == v.end()) {
                    res--;
                    break;
                }
                index = *it;
            }
        }
        return res;
    }
#endif
    // 装桶法
    /*
    将words 中的所有单词根据首字母来分桶，即：把所有单词按照首字母分到26个桶中，每个桶中存储的是所有以该字母开头的所有单词。
    然后我们从 s 的第一个字符开始遍历，假设当前字符为 'a'，我们从 'a' 开头的桶中取出所有单词。对于取出的每个单词，如果此
    时单词长度为1，说明该单词已经匹配完毕，我们将答案加1；否则我们将单词的首字母去掉，然后放入下一个字母开头的桶中，比如对于
    单词 "acd"，去掉首字母 'a' 后，我们将其放入 'c' 。
    */
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<string>> d(26);
        for (auto& w : words) d[w[0] - 'a'].emplace(w);
        int ans = 0;
        for (char& c : s) {
            auto& q = d[c - 'a'];
            for (int k = q.size(); k; --k) {
                auto t = q.front();
                q.pop();
                if (t.size() == 1) ++ans;
                else d[t[1] - 'a'].emplace(t.substr(1));
            }
        }
        return ans;
    }
};
