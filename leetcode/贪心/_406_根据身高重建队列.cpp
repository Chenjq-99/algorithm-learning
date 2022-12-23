#include<vector>
#include<list>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/queue-reconstruction-by-height/description/
class Solution {
    /*
    先按身高排好队，再优先按身高高的people的k来插队
    优先按照身高高的插队的原因，对于某个人，只有比他高的人都安置好了，他才能放心插队，不然
    如果还有比他高的人插到他的前面，他需要继续变换位置
    */
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        }

    #if 0
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (auto& person : people) {
            int index = person[1];
            res.insert(res.begin() + index, person);
        }
        return res;
    }
    #endif

    // vector insert操作效率比较低，使用链表
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> res;
        for (auto& person : people) {
            auto it = res.begin();
            int index = person[1];
            while(index-- > 0) it++; // list的迭代器不支持随机访问，只能从begin ++
            res.insert(it, person);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }

};