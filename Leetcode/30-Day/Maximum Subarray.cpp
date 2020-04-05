#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int running_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            running_sum = max(nums[i], running_sum + nums[i]);
            max_sum = max(max_sum, running_sum);
        }
        return max_sum;
    }
};