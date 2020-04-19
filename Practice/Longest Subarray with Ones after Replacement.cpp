#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*
    Problem Statement:
    Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, 
    find the length of the longest contiguous subarray having all 1s.
    
    Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
    Output: 6
    Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
    
    Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
    Output: 9
    Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9.
    */
   public:
    int findLength(const vector<int> &arr, int k) {
        int max_length = 0;
        int window_start = 0;
        int maxOneCounts = 0;
        for (int window_end = 0; window_end < arr.size(); window_end++) {
            if (arr[window_end] == 1) {
                maxOneCounts++;
            }
            // Track max one counts so we can replace remainings
            // If remaining replacement > k, shrink our window
            // Since it's only 0s or 1s, we can just subtract our maxOneCounts if value == 1,
            // otherwise shrink the window
            if (window_end - window_start + 1 - maxOneCounts > k) {
                if (arr[window_end] == 1) {
                    maxOneCounts--;
                }
                window_start++;
            }
            max_length = max(max_length, window_end - window_start + 1);
        }
        return max_length;
    }
};

int main() {
    Solution s;
    vector<int> arr = {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    int len = s.findLength(arr, 2);
    cout << len << endl;
}