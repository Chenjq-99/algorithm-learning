#include<vector>
using namespace std;
// https://leetcode.cn/problems/design-memory-allocator/
class Allocator {
private:
    vector<int> mem;
    int n;
public:
    Allocator(int n) {
        mem = vector<int>(n, -1);
        this->n = n;
    }
    
    int allocate(int size, int mID) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mem[i] != -1) cnt = 0;
            else cnt++;
            if (cnt == size) {
                for (int j = size - 1; j >= 0; j--) {
                    mem[i - j] = mID;
                }
                return i - size + 1;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mem[i] == mID) {
                cnt++;
                mem[i] = -1;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */