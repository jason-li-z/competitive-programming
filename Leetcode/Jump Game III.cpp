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

    bool canReachRecursive(vector<int> &arr, int start) {
        const int n = arr.size();
        vector<bool> seen(n);
        return helper(arr, seen, n, start);
    }

    bool helper(vector<int> &arr, vector<bool> &seen, int size, int index) {
        // Out of bounds checks, and base case
        if (index < 0 || index >= size || seen[index]) {
            return false;
        }

        if (arr[index] == 0) {  // If condition met (val == 0)
            return true;
        }
        seen[index] = true;

        if (helper(arr, seen, size, index + arr[index])) {  // Recurse plus, and minus
            return true;
        }
        if (helper(arr, seen, size, index - arr[index])) {
            return true;
        }

        return false;  // if doesn't hit recurse return case, we can simply return false
    }
};