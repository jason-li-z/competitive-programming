#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*
    Problem Statement:
    Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
    In other words, one of the first string's permutations is the substring of the second string.
    
    Input: String="oidbcaf", Pattern="abc"
    Output: true
    Explanation: The string contains "bca" which is a permutation of the given pattern.
    
    Input: String="odicf", Pattern="dc"
    Output: false
    Explanation: No permutation of the pattern is present in the given string as a substring.
    */
   public:
    bool findPermutation(const string &str, const string &pattern) {
        if (str == pattern) {
            return true;
        }
        unordered_map<char, int> count;
        int window_start = 0;
        int seen = 0;
        // Count the characters in pattern
        for (int i = 0; i < pattern.length(); i++) {
            count[pattern[i]]++;
        }

        for (int window_end = 0; window_end < str.length(); window_end++) {
            char current = str[window_end];
            // If current char in str exists in the Hashtable
            if (count.find(current) != count.end()) {
                count[current]--;  // Decrement it as we're adding it onto our window
                if (count[current] == 0) {
                    seen++;  // We've matched one fully in the string and pattern
                }
            }
            // If we've matched all to the length of the hashtable, we've found a match, return true
            if (seen == count.size()) {
                return true;
            }

            // If the window surpasses the pattern length, shrink our window to scan for pattern
            if (window_end >= pattern.length() - 1) {
                char start = str[window_start];
                if (count.find(start) != count.end()) {
                    // If we're removing the one we counted as "seen",
                    // We have to decrement from seen, and add the frequency back onto the hashtable
                    if (count[start] == 0) {
                        seen--;
                    }
                    count[start]++;
                }
                window_start++;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    string str = "oidbcaf";
    string pattern = "abc";
    int len = s.findPermutation(str, pattern);
    cout << len << endl;
}