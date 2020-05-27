#include <bits/stdc++.h>

using namespace std;

class Solution {
    /**
        Problem: Given a sorted array, create a new array containing squares 
        of all the number of the input array in the sorted order.

        Input: [-2, -1, 0, 2, 3]
        Output: [0, 1, 4, 4, 9].
    */
   public:
    // O(N) Time and Space
    vector<int> makeSquares(const vector<int> &arr) {
        int n = arr.size();
        vector<int> result(n);
        int largestSquareIdx = n - 1;  // populate result from n-1 => 0
        // Approach: Start from largest to smallest,
        // increment left if left is bigger, decrement right if right is bigger
        int left = 0, right = n - 1;
        while (left <= right) {
            int leftSquare = arr[left] * arr[left];
            int rightSquare = arr[right] * arr[right];
            if (leftSquare > rightSquare) {
                result[largestSquareIdx] = leftSquare;
                left++;
                largestSquareIdx--;
            } else {
                result[largestSquareIdx] = rightSquare;
                right--;
                largestSquareIdx--;
            }
        }
        return result;
    };

    // O(N lg N) time, O(N) space
    vector<int> makeSquares2(const vector<int> &arr) {
        int n = arr.size();
        vector<int> result(n);
        for (int i = 0; i < arr.size(); i++) {
            result[i] = arr[i] * arr[i];
        }
        sort(result.begin(), result.end());
        return result;
    };
};

int main() {
    Solution s;
    vector<int> arr = {-2, -1, 0, 2, 3};
    vector<int> result = s.makeSquares(arr);
    for (const auto &a : result) {
        cout << a << endl;
    }
}