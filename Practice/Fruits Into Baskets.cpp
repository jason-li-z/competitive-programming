#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*
    Problem Statement:
    Given an array of characters where each character represents a fruit tree,
    you are given two baskets and your goal is to put maximum number of fruits in each basket. 
    The only restriction is that each basket can have only one type of fruit.

    Input: Fruit=['A', 'B', 'C', 'A', 'C']
    Output: 3
    Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']
    
    Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
    Output: 5
    Explanation: We can put 3 'B' in one basket and two 'C' in the other basket. 
    This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']
    */
   public:
    int findLength(const vector<char> &arr) {
        unordered_map<char, int> count;  // To use as our "baskets" and track frequency
        int max_length = 0;              // Track max length
        int window_start = 0;            // Initial window size
        for (int window_end = 0; window_end < arr.size(); window_end++) {
            count[arr[window_end]]++;                 // Increment for this character/add to basket
            while (count.size() > 2) {                // Because we are only given 2 baskets
                count[arr[window_start]]--;           // Keep subtracting while we're over basket size
                if (count[arr[window_start]] == 0) {  // Remove completely
                    count.erase(arr[window_start]);
                }
                window_start++;  // Increment start as we've removed one
            }
            max_length = max(max_length, window_end - window_start + 1);  // Remember current max length
        }
        return max_length;
    }
};

int main() {
    Solution s;
    vector<char> arr = {'A', 'B', 'C', 'B', 'B', 'C'};
    int len = s.findLength(arr);
    cout << len << endl;
}