#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s : strs) {
            string original = s;
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(original);
        }
        vector<vector<string>> result;
        for(auto const &a : mp) {
            result.push_back(a.second);
        }
        return result;
    }
};