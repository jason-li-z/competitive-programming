#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*
    Problem Statement:
    Given a string, find the length of the longest substring which has no repeating characters.

    Input: String="aabccbb"
    Output: 3
    Explanation: The longest substring without any repeating characters is "abc".
    
    Input: String="abbbb"
    Output: 2
    Explanation: The longest substring without any repeating characters is "ab".
    */
   public:
    int findLength(const string &str) {
        int max_length = 0;
        int window_start = 0;
        unordered_map<char, int> count;
        for (int window_end = 0; window_end < str.length(); window_end++) {
            char current = str[window_end];
            // If hashtable already contains the current character, we can shrink our starting window
            // so that we only have 1 count of this character
            if (count.find(current) != count.end()) {
                // There won't be any index of current character after the previous index,
                // so it's either +1 or if the window is already ahead, we can just keep that
                window_start = max(window_start, count[current] + 1);  // If the current character already exist
                                                                       // Then we can update our starting window
                                                                       // to max of dup_char index+1 or our current
            }
            count[current] = window_end;  // Store the last seen index of this char into our hashtable
            max_length = max(max_length, window_end - window_start + 1);
        }
        return max_length;
    }
};

int main() {
    Solution s;
    string str = "aabccbb";
    int len = s.findLength(str);
    cout << len << endl;
}