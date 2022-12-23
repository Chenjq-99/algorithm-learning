#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        // ��������������ʱ: ������ + �Ҳ���� = ���С�� + �Ҳ�С��
        //                  ������ - ���С�� = �Ҳ�С�� - �Ҳ����
        // ����������ż��ʱ: ������ + �Ҳ���� - 1 = ���С�� + �Ҳ�С��
        //                  ������ - ���С�� - 1 = �Ҳ�С�� - �Ҳ���� 
        // �����ͱ������������֮�͵����⣬��hashMap��¼�ұ�������ٱ�����ߣ�ͳ�ƴ�
        // ע��ֻ��Ԫ��k��Ҳ��һ���������ʼ��cnt[0] = 1
        int idx = distance(nums.begin(), find(nums.begin(), nums.end(), k));
        unordered_map<int,int> cnt;
        cnt[0] = 1;
        int n = 0;
        for (int i = idx + 1; i < nums.size(); i++) {
            n += (nums[i] < k) ? 1 : -1;
            cnt[n]++;
        }
        n = 0;
        int res = cnt[0] + cnt[-1];
        for (int i = idx -1; i >= 0; i--) {
            n += (nums[i] > k) ? 1 : -1;
            res += cnt[n] + cnt[n-1];
        }
        return res;
    }
};
