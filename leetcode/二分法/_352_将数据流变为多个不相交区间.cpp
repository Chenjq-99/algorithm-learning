#include<vector>
#include<map>
using namespace std;
// https://leetcode.cn/problems/data-stream-as-disjoint-intervals/description/
class SummaryRanges {
private:
    map<int, int> intervals;
public:
    SummaryRanges() {}
    
    void addNum(int val) {
        // �ҵ����������������������� [l0, r0], [l1, r1] ���� l0 <= val < l1;
        auto itl1 = intervals.upper_bound(val);
        // ��� itl1 == begin, ��ô��û�е�һ�����䣬��itl0 = end, ����itl0 = --itl1��
        auto itl0 = (itl1 == intervals.begin()) ? intervals.end() : prev(itl1);
        if (itl0 != intervals.end() && itl0->first <= val && itl0->second >= val) {
            // ���һ��val������[l0, r0]�м䣬���ֲ���
            return;
        } else {
            bool flag1 = (itl0 != intervals.end() && itl0->second + 1 == val);
            bool flag2 = (itl1 != intervals.end() && itl1->first - 1 == val);
            if (flag1 && flag2) {
                // �������val����������������һ��������
                // �õ������������
                int left = itl0->first, right = itl1->second;
                intervals.erase(itl0);
                intervals.erase(itl1);
                intervals.emplace(left, right);
            } else if (flag1) {
                // �������val������[l0, r0]���
                itl0->second = val;
            } else if (flag2) {
                // ����ģ�val����[l1, r1]ǰ��
                int right = itl1->second;
                intervals.erase(itl1);
                intervals.emplace(val, right);
            } else {
                // ����壺val��������
                intervals.emplace(val, val);
            }
        }

    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& [l, r] : intervals) {
            res.push_back({l, r});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */