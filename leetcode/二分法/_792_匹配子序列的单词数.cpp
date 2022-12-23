#include<vector>
#include<queue>
#include<string>
using namespace std;

// https://leetcode.cn/problems/number-of-matching-subsequences/description/
class Solution {
public:
#if 0
    // ���ַ�
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
    // װͰ��
    /*
    ��words �е����е��ʸ�������ĸ����Ͱ�����������е��ʰ�������ĸ�ֵ�26��Ͱ�У�ÿ��Ͱ�д洢���������Ը���ĸ��ͷ�����е��ʡ�
    Ȼ�����Ǵ� s �ĵ�һ���ַ���ʼ���������赱ǰ�ַ�Ϊ 'a'�����Ǵ� 'a' ��ͷ��Ͱ��ȡ�����е��ʡ�����ȡ����ÿ�����ʣ������
    ʱ���ʳ���Ϊ1��˵���õ����Ѿ�ƥ����ϣ����ǽ��𰸼�1���������ǽ����ʵ�����ĸȥ����Ȼ�������һ����ĸ��ͷ��Ͱ�У��������
    ���� "acd"��ȥ������ĸ 'a' �����ǽ������ 'c' ��
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
