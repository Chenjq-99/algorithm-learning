#include<vector>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/
class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // ��һ��
        for (int i = 0; i < A.size(); i++) { // �ڶ���
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // ������
        int result = 0;
        for (int a : A) result += a;        // ���Ĳ�
        return result;
    }
};