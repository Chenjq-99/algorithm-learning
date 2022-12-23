#include<vector>
using namespace std;
// https://leetcode.cn/problems/jump-game/description/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // ֻ��һ��Ԫ�أ������ܴﵽ
        for (int i = 0; i <= cover; i++) { // ע��������С�ڵ���cover ����cover�ķ�Χ����չcover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // ˵�����Ը��ǵ��յ���
        }
        return false;
    }
};

