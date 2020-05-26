#include <bits/stdc++.h>

using namespace std;

class Solution {
    /* 
    Given an array of positive numbers and a positive number ‘sum’, find the length of the smallest 
    contiguous subarray whose sum is >= to ‘sum’. Return 0, if no such subarray exists.
    
    Input: [2, 1, 5, 2, 3, 2], sum=7 
    Output: 2
    Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].

    Input: [2, 1, 5, 2, 8], sum=7 
    Output: 1
    Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].
    */
   public:
    int findMinSubArray(int s, vector<int>& nums) {
        if (nums.size() < 1) {
            return 0;
        }
        int min_length = INT_MAX;
        int running_sum = 0;
        int window_start = 0;
        for (int window_end = 0; window_end < nums.size(); window_end++) {
            running_sum += nums[window_end];
            while (running_sum >= s) {
                min_length = min(min_length, window_end - window_start + 1);
                running_sum -= nums[window_start];
                window_start++;
            }
        }

        if (min_length == INT_MAX) {
            return 0;
        }

        return min_length;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 1, 5, 2, 8};
    int sum = s.findMinSubArray(7, nums);
    cout << sum << endl;
}