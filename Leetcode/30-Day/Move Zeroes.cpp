#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        int num = 0;
        int i = 0;
        while (zero < nums.size() && i < nums.size()) {
            if (nums[i] != 0) {
                swap(nums[i], nums[zero]);
                zero++;
            }
            i++;
        }
    }
};