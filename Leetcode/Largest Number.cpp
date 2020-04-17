#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    static bool comparison(const int &num1, const int &num2) {
        string result1 = "";
        string result2 = "";
        result1 = result1 + (to_string(num1) + to_string(num2));
        result2 = result2 + (to_string(num2) + to_string(num1));
        return stoll(result1) > stoll(result2);
    };

    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), comparison);
        string result = "";
        for (int i = 0; i < nums.size(); i++) {
            result = result + to_string(nums[i]);
        }
        if (result[0] == '0' && result.length() > 1) {
            result = "0";
        }
        return result;
    }
};