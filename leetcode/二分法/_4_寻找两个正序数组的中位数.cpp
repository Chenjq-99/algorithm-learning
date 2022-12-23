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
            // Ҫ������϶�����nums1��ǰk/2��
            return findKthValue(nums1, nums2, b1 + k/2, b2, k-k/2);
        }else{
            return findKthValue(nums1, nums2, b1, b2 + k/2, k-k/2);
        }
    }
};

#if 0
    �������ѵ�����������������������������ҵ���k��Ԫ��
    ���ö��ַ�������1���ҵ���k/2��Ԫ�أ�����������ҵ���k/2��Ԫ��
    �Ƚ���������ĵ�k/2��Ԫ�صĴ�С����������ĵ�k��Ԫ�ؿ϶����ڵ�k/2Ԫ�ؽ�С�������ǰk/2����
    (��Ϊ����ڵ�k/2Ԫ�ؽ�С�������ǰk/2�����ô<=k/2 + <k/2 һ�� < k),�����̭��һ�������k/2��Ԫ�أ�
    �ݹ���ң����ҵ����+k/2,���ҵ�λ��-k/2��ֱ���ҵ���k��Ԫ��
#endif