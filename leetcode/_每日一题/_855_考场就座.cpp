#include<set>
#include<queue>
using namespace std;
// https://leetcode.cn/problems/exam-room/
struct Comp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        int d1 = p1.second - p1.first, d2 = p2.second - p2.first;
        return d1 / 2 < d2 / 2 || (d1 / 2 == d2 / 2 && p1.first > p2.first);
    }
};

class ExamRoom {
private:
    int n;
    set<int> seats;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

public:
    ExamRoom(int n) : n(n) {}

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        int left = *seats.begin(), right = n - 1 - *seats.rbegin();
        while (seats.size() >= 2) {
            auto p = pq.top();
            if (seats.count(p.first) > 0 && seats.count(p.second) > 0 && 
                *next(seats.find(p.first)) == p.second) { // �������ӳ�ɾ��������
                int d = p.second - p.first;
                if (d / 2 < right || d / 2 <= left) { // ��������ҵ���λ����
                    break;
                }
                pq.pop();
                pq.push({p.first, p.first + d / 2});
                pq.push({p.first + d / 2, p.second});
                seats.insert(p.first + d / 2);
                return p.first + d / 2;
            }
            pq.pop(); // leave �������ӳ�ɾ���������ڴ�ʱɾ��
        }
        if (right > left) { // ���ҵ�λ�ø���
            pq.push({*seats.rbegin(), n - 1});
            seats.insert(n - 1);
            return n - 1;
        } else {
            pq.push({0, *seats.begin()});
            seats.insert(0);
            return 0;
        }
    }

    void leave(int p) {
        if (p != *seats.begin() && p != *seats.rbegin()) {
            auto it = seats.find(p);
            pq.push({*prev(it), *next(it)});
        }
        seats.erase(p);
    }
};