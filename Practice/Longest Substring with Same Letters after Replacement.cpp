#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*
    Problem Statement:
    Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ 
    letters with any letter, find the length of the longest substring having the same letters after replacement.
    
    Input: String="aabccbb", k=2
    Output: 5
    Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".
    
    Input: String="abbcb", k=1
    Output: 4
    Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".
    */
   public:
    int findLength(const string &str, int k) {
        int max_length = 0;
        int max_count = 0;
        int window_start = 0;
        unordered_map<char, int> count;
        for (int window_end = 0; window_end < str.length(); window_end++) {
            char current = str[window_end];
            count[current]++;
            max_count = max(max_count, count[current]);
            // Max_count as "max" times that character can appear in our window
            // We know we can replace the remaining characters after finding our max count
            // So we can use our window to subtract the max_count to get remaining
            // If remaining replacement > k, shrink down window
            if (window_end - window_start + 1 - max_count > k) {
                count[str[window_start]]--;
                if (count[str[window_start]] == 0) {
                    count.erase(str[window_start]);
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
    string str = "aabccbb";
    int len = s.findLength(str, 2);
    cout << len << endl;
}