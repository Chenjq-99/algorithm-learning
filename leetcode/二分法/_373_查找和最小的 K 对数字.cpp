#include<vector>
#include<queue>
using namespace std;


class Solution {
    typedef pair<int, int> PII;
public:
    // 多路归并
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> res;
        auto cmp = [&](const PII& a, const PII& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
        for (int i = 0; i < n; i++) {
            heap.emplace(i, 0);
        }
        while (res.size() < k && heap.size()) {
            auto [i, j] = heap.top();
            heap.pop();
            res.push_back({nums1[i],nums2[j]});
            if (j + 1 < m) heap.emplace(i, j + 1);
        }
        return res;
    }
};


class Solution {
public:
    // 二分查找
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> res;
        // 参考378. 有序矩阵中第 K 小的元素，其实两个数组联合就是二维n * m有序矩阵
        auto count = [&](int tar){ // 求矩阵中小于等于tar的数对数量是否大于等于k个
            int i = n - 1, j = 0;
            long long cnt = 0;
            while (i >= 0 && j < m) {
                if (nums1[i] + nums2[j] <= tar) cnt += i + 1, j++;
                else i--;
            }
            return cnt >= k;
        };
        // 找到满足小于x的数对数量大于等于k的最小x
        int l = nums1[0] + nums2[0], r = nums1[n - 1] + nums2[m - 1];
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (count(mid)) r = mid;
            else l = mid + 1;
        }
        int x = l;
        // 把小于x的数对加入到答案中
        // 枚举nums1，二分查找nums2
        for (int i = 0; i < n; i++) {
            // 在nunms2 找 nums1[i] + nums[l] < x 即 nums[l] < x - nums[i] 的最大下标l
            int l = 0, r = m - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (nums2[mid] < x - nums1[i]) l = mid;
                else r = mid - 1;
            }
            // 判断l是否合法
            if (nums1[i] + nums2[l] >= x) break;
            // 把(i, 0) - (i, l) 加入答案
            for (int j = 0; j <= l; j++) {
                res.push_back({nums1[i], nums2[j]});
            }
        }
        // 用等于x的数对补齐
        k -= res.size();
        for (int i = 0; i < n; i++) {
            // 在nunms2中找第一个大于等于 x - nums[i]的数, 又tm是二分
            int l = 0, r = m - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (nums2[mid] >= x - nums1[i]) r = mid;
                else l = mid + 1;
            }
            if (nums2[l] != x - nums1[i]) continue;
            int j = l;
            while (j < m && nums1[i] + nums2[j] == x && k > 0) {
                res.push_back({nums1[i], nums2[j]});
                j++;
                k--;
            }
            if (k == 0) break;
        }
        return res;
    }
};