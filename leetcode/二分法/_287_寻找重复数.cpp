#include<vector>
using namespace std;
// https://leetcode.cn/problems/find-the-duplicate-number/
class Solution {
public:
// ���ַ�
// ͳ��������С�ڵ���mid�����ָ��������mid < cnt ˵�� �� <= mid
// ����  6 4 5 2 1 2 3
// cnt:  1->1 2->3  3->4 4->5 5->6 6->7
    int findDuplicate1(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l >> 1);
            int cnt = 0;
            for (int i = 0; i <= n; i++) {
                cnt += (nums[i] <= mid);
            }
            if (mid < cnt) r = mid;
            else l = mid + 1;
        }
        return l;
    }
// ����ָ��
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};