#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> n;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(map.find(diff) != map.end()) {
                n.push_back(i);
                n.push_back(map[diff]);
                return n;
            }
            map[nums[i]] = i;
        }
        return n;
    }
};