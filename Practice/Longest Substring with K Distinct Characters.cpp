#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*

    Problem: Given a string, find the length of the longest substring in it with
    no more than K distinct characters.

    Input: String="araaci", K=2
    Output: 4
    Explanation: The longest substring with no more than '2' distinct characters is "araa".
    
    Input: String="araaci", K=1
    Output: 2
    Explanation: The longest substring with no more than '1' distinct characters is "aa".
    
    */
   public:
    int findLength(const string &str, int k) {
        if (str.length() == 0) {
            return 0;
        }
        unordered_map<char, int> count;
        int max_length = 0;
        int window_start = 0;
        for (int window_end = 0; window_end < str.length(); window_end++) {
            count[str[window_end]]++;                 // Increment the character
            while (count.size() > k) {                // If hashtable > k, there's more than K distinct
                count[str[window_start]]--;           // Remove the first character from our "window"
                if (count[str[window_start]] == 0) {  // Can completely remove it from the hashtable if char no longer exist
                    count.erase(str[window_start]);
                }
                window_start++;  // Increment left window
            }
            max_length = max(max_length, window_end - window_start + 1);  // Rememeber our max length
        }
        return max_length;
    }
};

int main() {
    Solution s;
    string str = "aaabb";
    int len = s.findLength(str, 3);
    cout << len << endl;
}