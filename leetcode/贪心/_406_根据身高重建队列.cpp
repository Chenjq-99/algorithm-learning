#include<vector>
#include<list>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/queue-reconstruction-by-height/description/
class Solution {
    /*
    �Ȱ�����źöӣ������Ȱ���߸ߵ�people��k�����
    ���Ȱ�����߸ߵĲ�ӵ�ԭ�򣬶���ĳ���ˣ�ֻ�б����ߵ��˶����ú��ˣ������ܷ��Ĳ�ӣ���Ȼ
    ������б����ߵ��˲嵽����ǰ�棬����Ҫ�����任λ��
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

    // vector insert����Ч�ʱȽϵͣ�ʹ������
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> res;
        for (auto& person : people) {
            auto it = res.begin();
            int index = person[1];
            while(index-- > 0) it++; // list�ĵ�������֧��������ʣ�ֻ�ܴ�begin ++
            res.insert(it, person);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }

};