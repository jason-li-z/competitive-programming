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
    static pair<int, int> search(const vector<int>& arr, int targetSum) {
        int start = 0;
        int end = arr.size() - 1;
        while (start < end) {
            if (arr[start] + arr[end] == targetSum) {
                return make_pair(start, end);
            }

            if (arr[start] + arr[end] > targetSum) {
                end--;
            } else {
                start++;
            }
        }
    }
};

int main() {
    int target = 6;
    vector<int> arr = {1, 2, 3, 4, 6};
    pair<int, int> indices = Solution::search(arr, target);
    cout << indices.first << " " << indices.second << endl;
}