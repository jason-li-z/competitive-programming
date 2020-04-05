#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int solution = 0;
        for (int i = 0; i < nums.size(); i++) {
            solution ^= nums[i];
        }
        return solution;
    }
};