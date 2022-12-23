#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        int left = (s1 + s2 + 1) / 2;
        int right = (s1 + s2 + 2) / 2;
        return (findKthValue(nums1, nums2, 0, 0, left) + findKthValue(nums1, nums2, 0, 0, right))/2.0;
    }
private:
    int findKthValue(vector<int>& nums1, vector<int>& nums2, int b1, int b2, int k){
        if(b1 >= nums1.size()) return nums2[b2 + k -1];
        if(b2 >= nums2.size()) return nums1[b1 + k -1];
        if(k == 1) return min(nums1[b1],nums2[b2]);
        int midValue1 = (b1 + k/2 - 1 < nums1.size()) ? nums1[b1 + k/2 - 1] : INT32_MAX;
        int midValue2 = (b2 + k/2 - 1 < nums2.size()) ? nums2[b2 + k/2 - 1] : INT32_MAX;
        if(midValue1 < midValue2){
            // 要查的数肯定不在nums1的前k/2个
            return findKthValue(nums1, nums2, b1 + k/2, b2, k-k/2);
        }else{
            return findKthValue(nums1, nums2, b1, b2 + k/2, k-k/2);
        }
    }
};

#if 0
    这道题的难点在于如何在两个有序数组联合中找到第k个元素
    利用二分法在数组1中找到第k/2个元素，在数组二中找到第k/2个元素
    比较两个数组的第k/2个元素的大小，联合数组的第k个元素肯定不在第k/2元素较小的数组的前k/2个里
    (因为如果在第k/2元素较小的数组的前k/2个里，那么<=k/2 + <k/2 一定 < k),因此淘汰了一个数组的k/2个元素，
    递归查找，查找的起点+k/2,查找的位置-k/2，直至找到第k个元素
#endif