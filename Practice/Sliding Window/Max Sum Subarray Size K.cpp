#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*
    Example 1:
    Input: nums = [1, -1, 5, -2, 3], k = 3
    Output: 4 
    Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
    
    Example 2:
    Input: nums = [-2, -1, 2, 1], k = 1
    Output: 2 
    Explanation: The subarray [-1, 2] sums to 1 and is the longest.
    */
   public:
    int findMaxSumSubarray(vector<int>& nums, int k) {
        int max_sum = 0;
        int window_start = 0;
        int running_sum = 0;
        for (int window_end = 0; window_end < nums.size(); window_end++) {
            running_sum += nums[window_end];
            if (window_end >= k - 1) {
                max_sum = max(running_sum, max_sum);
                running_sum -= nums[window_start];
                window_start++;
            }
        }
        return max_sum;
    }

    int bruteforce(vector<int>& nums, int k) {
        int max_sum = 0;
        for (int i = 0; i < nums.size() - k; i++) {
            int running_sum = 0;
            for (int j = i; j < i + k; j++) {
                running_sum += nums[j];
            }
            max_sum = max(running_sum, max_sum);
        }
        return max_sum;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 4, 1, 5};
    int sum = s.bruteforce(nums, 2);
    cout << sum << endl;
}