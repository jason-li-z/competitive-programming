#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> s;

        while (s.find(n) == s.end()) {
            // n = sum of (% 10 ^ 2)
            s.insert(n);
            int tmp = n;
            int sum = 0;
            while (tmp > 0) {
                sum += pow(tmp % 10, 2);
                tmp /= 10;
            }
            if (sum == 1) {
                return true;
            }
            n = sum;
        }
        return false;
    }
};