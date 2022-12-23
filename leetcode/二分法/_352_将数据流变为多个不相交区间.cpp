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
        // 找到离待插入数最近的两个区间 [l0, r0], [l1, r1] 满足 l0 <= val < l1;
        auto itl1 = intervals.upper_bound(val);
        // 如果 itl1 == begin, 那么就没有第一个区间，让itl0 = end, 否则itl0 = --itl1；
        auto itl0 = (itl1 == intervals.begin()) ? intervals.end() : prev(itl1);
        if (itl0 != intervals.end() && itl0->first <= val && itl0->second >= val) {
            // 情况一：val落在了[l0, r0]中间，保持不变
            return;
        } else {
            bool flag1 = (itl0 != intervals.end() && itl0->second + 1 == val);
            bool flag2 = (itl1 != intervals.end() && itl1->first - 1 == val);
            if (flag1 && flag2) {
                // 情况二：val把两个区间连城了一个大区间
                // 拿到大区间的两端
                int left = itl0->first, right = itl1->second;
                intervals.erase(itl0);
                intervals.erase(itl1);
                intervals.emplace(left, right);
            } else if (flag1) {
                // 情况三：val接在了[l0, r0]后边
                itl0->second = val;
            } else if (flag2) {
                // 情况四：val接在[l1, r1]前边
                int right = itl1->second;
                intervals.erase(itl1);
                intervals.emplace(val, right);
            } else {
                // 情况五：val独立成组
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