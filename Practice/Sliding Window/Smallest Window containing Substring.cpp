#include <bits/stdc++.h>

using namespace std;

class Solution {
    /* 
    Given a string and a pattern, find the smallest substring in the given 
    string which has all the characters of the given pattern.
    
    Input: String="aabdec", Pattern="abc"
    Output: "abdec"
    Explanation: The smallest substring having all characters of the pattern is "abdec"

    Input: String="abdabca", Pattern="abc"
    Output: "abc"
    Explanation: The smallest substring having all characters of the pattern is "abc".
    */
   public:
    static string findSubstring(const string& str, const string& pattern) {
        unordered_map<char, int> count;
        // Count frequencies of character in pattern
        for (int i = 0; i < pattern.length(); i++) {
            count[pattern[i]]++;
        }

        int windowStart = 0;
        int found = 0;  // For matching
        string result = "";

        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char current = str[windowEnd];
            // If this char is in the map, decrement by one until 0
            if (count.find(current) != count.end()) {
                count[current]--;
                if (count[current] == 0) {  // Once we've hit 0, we've found a match
                    found++;
                }
            }
            // Attempt to shrink our window once we've found a complete match
            while (found == count.size()) {
                // If the string is empty, then we'll update it once
                result = str.substr(windowStart, windowEnd - windowStart + 1);
                // Shrinking from left
                char left = str[windowStart++];
                if (count.find(left) != count.end()) {
                    if (count[left] == 0) {
                        found--;
                    }
                    count[left]++;
                }
            }
        }
        return result;
    }
};

int main() {
    string str = "ab";
    string anagram = "A";
    string result = Solution::findSubstring(str, anagram);
    cout << result << endl;
}