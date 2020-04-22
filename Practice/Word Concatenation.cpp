#include <bits/stdc++.h>

using namespace std;

class Solution {
    /* 
    Given a string and a list of words, find all the starting indices of substrings 
    in the given string that are a concatenation of all the given words exactly once without any overlapping of words. 
    It is given that all words are of the same length.
    
    Input: String="catfoxcat", Words=["cat", "fox"]
    Output: [0, 3]
    Explanation: The two substring containing both the words are "catfox" & "foxcat".
    
    Input: String="catcatfoxfox", Words=["cat", "fox"]
    Output: [3]
    Explanation: The only substring containing both the words is "catfox".
    */
   public:
    static vector<int> findSubstring(const string& str, const vector<string>& words) {
        unordered_map<string, int> wordCount;

        for (const auto& word : words) {
            wordCount[word]++;
        }

        vector<int> indices;
        int totalWords = words.size();
        int wordLength = words[0].length();

        // We want to see if we find the concatenated word at the ith index
        for (int i = 0; i <= str.length() - totalWords * wordLength; i++) {
            unordered_map<string, int> wordsSeen;
            for (int j = 0; j < totalWords; j++) {
                int nextWordIdx = i + j * wordLength;
                string word = str.substr(nextWordIdx, wordLength);
                // If the substring word is not in our hashtable, we can just exit
                if (wordCount.find(word) == wordCount.end()) {
                    break;
                }
                // Otherwise, mark the word as seen
                wordsSeen[word]++;
                // If it goes over frequency of how many times it occurs, we can just return
                if (wordsSeen[word] > wordCount[word]) {
                    break;
                }
                // If we've made it all the way through, it's a match
                if (j + 1 == totalWords) {
                    indices.push_back(i);
                }
            }
        }

        return indices;
    }
};

int main() {
    string str = "catfoxcat";
    vector<string> words = {"cat", "fox"};
    vector<int> indices = Solution::findSubstring(str, words);
    for (const auto& a : indices) {
        cout << a << endl;
    }
}