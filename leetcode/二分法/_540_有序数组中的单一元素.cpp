#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums){
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(checkSingle(nums,mid)) return nums[mid];
            if(nums[mid] == nums[mid-1]){
                if(mid%2 == 0) r = mid - 2;
                else l = mid + 1;
            }else{
                if(mid%2 == 0) l = mid + 2;
                else r = mid - 1;
            }
        }
        return 0;
    }
private:
    bool checkSingle(vector<int>& nums, int index){ // �������� ���ڼ��һ��Ԫ���Ƿ�Ϊ��һԪ��
        if(nums.size() == 1) return true;
        if(index == 0) return nums[index] != nums[index+1];
        if(index == nums.size() - 1) return nums[index] != nums[index-1];
        return nums[index] != nums[index-1] && nums[index] != nums[index+1];
    }
};

#if 0
    ������ǳ���Ķ��ַ�+����ж�l r�ƶ�����
    ��nums[mid]��ֵ����singleʱ
        ���nums[mid] == nums[mid+1], ��mid���������Ԫ��ֵ��ȣ���ʱ
            ��mid��ż������ô��ǰ����ż����Ԫ�أ���������ԣ���ôǰ���������ģ�mid��mid+1��ԣ�lֱ������mid+2��
            ��mid����������ô��ǰ����������Ԫ�أ�������ԣ� ��ôǰ�治������rֱ������mid-1;
        nums[mid] == nums[mid-1]��ʱ��ͬ��
#endif