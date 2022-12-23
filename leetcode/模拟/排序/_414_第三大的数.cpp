#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/third-maximum-number/description/
class Solution {

// 去重+快选 O(n) 空间复杂度比较大
static const int N = 1e4 + 10;
int q[N];
unordered_map<int,bool> f;
int n, num = 0;

int quick_select(int q[], int l, int r, int k) {
    if (l >= r) return q[l];
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (q[i] > x);
        do j--; while (q[j] < x);
        if (i < j) swap(q[i], q[j]);
    }
    int left = j - l + 1;
    if (left >= k) return quick_select(q, l, j, k);
    else return quick_select(q, j + 1, r, k - left);
}
public:
    int thirdMax(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < n; i++) {
            if (f[nums[i]] == false) {
                q[num++] = nums[i];
                f[nums[i]] = true;
            }
        }
        if (num == 1) return q[0];
        if (num == 2) return max(q[0], q[1]);
        return quick_select(q, 0, num - 1, 3);
    }
};

// 排序 遍历 O(nlogn)
class Solution {
public:
    int thirdMax(vector<int> &nums) {
        sort(nums.begin(), nums.end(), greater<>());
        for (int i = 1, diff = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] && ++diff == 3) { // 此时 nums[i] 就是第三大的数
                return nums[i];
            }
        }
        return nums[0];
    }
};
