#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
   public:
    /**
     * Given an array of non-negative integers arr, 
     * you are initially positioned at start index of the array. 
     * When you are at index i, you can jump to i + arr[i] or i - arr[i], 
     * check if you can reach to any index with value 0.
     */
    bool canReach(vector<int> &arr, int start) {
        const int n = arr.size();
        vector<bool> seen(n);
        queue<int> queue;
        queue.push(start);
        while (!queue.empty()) {
            int index = queue.front();
            queue.pop();
            if (arr[index] == 0) {
                return true;
            }
            seen[index] = true;
            int plus = index + arr[index];
            int minus = index - arr[index];
            if (plus < n) {
                if (!seen[plus]) {
                    queue.push(plus);
                }
            }
            if (minus >= 0) {
                if (seen[minus] == false) {
                    queue.push(minus);
                }
            }
        }
        return false;
    }
};