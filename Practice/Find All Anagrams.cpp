#include <bits/stdc++.h>

using namespace std;

class Solution {
    /* 
    Given a string and a pattern, find all anagrams of the pattern in the given string.
    
    Input: String="ppqp", Pattern="pq"
    Output: [1, 2]
    Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".

    Input: String="abbcabc", Pattern="abc"
    Output: [2, 3, 4]
    Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc".
    */
   public:
    static vector<int> findAnagrams(const string& str, const string& anagram) {
        vector<int> indices;
        unordered_map<char, int> count;
        for (int idx = 0; idx < anagram.length(); idx++) {
            count[anagram[idx]]++;
        }

        int found = 0;
        int windowStart = 0;

        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char current = str[windowEnd];

            if (count.find(current) != count.end()) {
                count[current]--;
                if (count[current] == 0) {
                    found++;
                }
            }

            if (found == count.size()) {
                indices.push_back(windowStart);
            }

            if (windowEnd - windowStart + 1 >= anagram.length()) {
                char left = str[windowStart];
                if (count.find(left) != count.end()) {
                    if (count[left] == 0) {
                        found--;
                    }
                    count[left]++;
                }
                windowStart++;
            }
        }
        return indices;
    }
};

int main() {
    string str = "abbcabc";
    string anagram = "abc";
    vector<int> result = Solution::findAnagrams(str, anagram);
    for (const auto& a : result) {
        cout << a << endl;
    }
}