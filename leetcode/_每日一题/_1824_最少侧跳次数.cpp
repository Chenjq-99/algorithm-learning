#include<vector>
using namespace std;
// https://leetcode.cn/problems/minimum-sideway-jumps/
class Solution {
    /*
    ��f[i][j] ��ʾ�����i��λ�õĵ�j���ܵ���С�Ĳ�������
    �ʼ���뷨�Ƕ���f[i][j] ȡmin{��ͬһ�ܵ�ת�ƶ������������ܵ���������}
    ���������ô��������ͬһ��λ�������ܵ��໥��������֪���ȸ�����һ�������仰˵�������޺�Ч��
    ���ƣ��Ⱥ�����£�һ�����ܵ�ͨ��������´ﵽ������ֵ(��֤��)
    ����û�дﵽ����ֵ���ܵ�������ͨ���Ѿ��ﵽ����ֵ���ܵ����¹���
    �Ѿ��ﵽ����ֵ���ܵ��򲻻��������ܵ���Ӱ��
    �����Ϳ��������޺�Ч�ԣ����ÿ��������ܵ��ĸ���˳��
    */ 
public:
    int minSideJumps(vector<int>& obs) {
        int f[3] = {1, 0, 1};
        int n = obs.size() - 1;
        for (int i = 1; i <= n; i++) {
            // �������
            for (int j = 0; j < 3; j++)
                if (obs[i] == j + 1) f[j] = 0x3f3f3f3f;
            // �������
            for (int j = 0; j < 3; j++) {
                if (obs[i] == j + 1) continue;
                for (int k : {(j + 1) % 3, (j + 2) % 3})
                    f[j] = min(f[j], f[k] + 1);
            }
        }
        return min(f[0], min(f[1], f[2]));
    }
};

class Solution {
    /*
    ��������һ���뷨��
    �����i��λ�ò����ϰ��� f[i][j] = f[i - 1][j]
    �������������ܵ�k�����kû���ϰ�����
    f[i][j] = min(f[i][j], f[i - 1][k] + 1)
    ��ʵ�����ϻ����Ⱥ�����£����������
    */ 
public:
    int minSideJumps(vector<int>& obs) {
        int f[3] = {1, 0, 1};
        int n = obs.size() - 1;
        for (int i = 1; i <= n; i++) {
            int pos = obs[i] - 1;
            for (int j = 0; j < 3; j++) {
                if (j == pos) {
                    f[j] = 0x3f3f3f3f;
                    continue;
                } 
                for (int k : {(j + 1) % 3, (j + 2) % 3}) 
                    if (k != pos) f[j] = min(f[j], f[k] + 1);
            }
        }
        return min(f[0], min(f[1], f[2]));
    }
};
