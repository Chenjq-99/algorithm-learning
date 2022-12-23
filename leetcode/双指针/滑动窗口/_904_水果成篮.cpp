#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int total = 0;
        int fruit_type = 0;
        unordered_map<int,int> basket;
        for(int j = 0; j < fruits.size(); j++){
            if(basket[fruits[j]] == 0){
                fruit_type++;
            }
            basket[fruits[j]]++;
            while(fruit_type > 2){
                basket[fruits[i]]--;
                if(basket[fruits[i]] == 0) fruit_type--;
                i++;
            }
            total = total > j - i + 1 ? total : j - i + 1;
        }
        return total;
    }
};