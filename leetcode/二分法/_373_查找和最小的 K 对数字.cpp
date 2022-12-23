#include<vector>
#include<queue>
using namespace std;


class Solution {
    typedef pair<int, int> PII;
public:
    // ��·�鲢
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
    // ���ֲ���
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> res;
        // �ο�378. ��������е� K С��Ԫ�أ���ʵ�����������Ͼ��Ƕ�άn * m�������
        auto count = [&](int tar){ // �������С�ڵ���tar�����������Ƿ���ڵ���k��
            int i = n - 1, j = 0;
            long long cnt = 0;
            while (i >= 0 && j < m) {
                if (nums1[i] + nums2[j] <= tar) cnt += i + 1, j++;
                else i--;
            }
            return cnt >= k;
        };
        // �ҵ�����С��x�������������ڵ���k����Сx
        int l = nums1[0] + nums2[0], r = nums1[n - 1] + nums2[m - 1];
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (count(mid)) r = mid;
            else l = mid + 1;
        }
        int x = l;
        // ��С��x�����Լ��뵽����
        // ö��nums1�����ֲ���nums2
        for (int i = 0; i < n; i++) {
            // ��nunms2 �� nums1[i] + nums[l] < x �� nums[l] < x - nums[i] ������±�l
            int l = 0, r = m - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (nums2[mid] < x - nums1[i]) l = mid;
                else r = mid - 1;
            }
            // �ж�l�Ƿ�Ϸ�
            if (nums1[i] + nums2[l] >= x) break;
            // ��(i, 0) - (i, l) �����
            for (int j = 0; j <= l; j++) {
                res.push_back({nums1[i], nums2[j]});
            }
        }
        // �õ���x�����Բ���
        k -= res.size();
        for (int i = 0; i < n; i++) {
            // ��nunms2���ҵ�һ�����ڵ��� x - nums[i]����, ��tm�Ƕ���
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