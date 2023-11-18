#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

int grid[9][9];

bool check(vector<int>& nums) {
	bool res = true;
	map<int, int> mp;
	// for (int i = 0; i < 9; i++) {
	// 	cout << nums[i] << " ";
	// }
	// cout << endl;
	for (auto& x : nums) {
		if (mp[x] != 0) {
			res = false;
			break;
		} else {
			mp[x]++;
		}
	}
	return res;
}

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < 9; i++) {
    	for (int j = 0; j < 9; j++) {
    		cin >> grid[i][j];
    		// cout << grid[i][j] << " ";
    	}
    	// cout << endl;
    }
    vector<int> nums(9);
    bool ok = false;
    for (int i = 0; i < 9; i++) {
    	for (int j = 0; j < 9; j++) {
    		nums[j] = grid[i][j];
    	}
    	ok = check(nums);
    	if (!ok) {
			break;
		}
    }
    if (ok) {
    	for (int j = 0; j < 9; j++) {
    		for (int i = 0; i < 9; i++) {
    			nums[i] = grid[i][j];
    		}
    		ok = check(nums);
    		if (!ok) {
    			break;
    		}
    	}
    }
    if (ok) {
    	for (int i = 0; i < 9; i+= 3) {
    		for (int j = 0; j < 9; j+= 3) {
    			int cnt = 0;
    			for (int x = 0; x < 3; x++) {
    				for (int y = 0; y < 3; y++) {
    					nums[cnt++] = grid[i + x][j + y];
    				}
    			}
    			ok = check(nums);
	    		if (!ok) {
	    			break;
	    		}
    		}
    	}
    }
    if (ok) {
    	puts("Yes");
    } else {
    	puts("No");
    }
	return 0;
}