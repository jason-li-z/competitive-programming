#include <bits/stdc++.h>

using namespace std;

class Solution {
    /**
        Input: [3, 2, 3, 6, 3, 10, 9, 3], Key=3
        Output: 4
        Explanation: The first four elements after removing every 'Key' will be [2, 6, 10, 9].
    */
   public:
    int removeKey(vector<int> &arr, int key) {
        if (arr.size() == 0) {
            return 0;
        }
        int nextElement = 0;  // index to represent next element, our "slow" pointer
        // We can return nextElement as it will represent the # of element in array
        for (int i = 0; i < arr.size(); i++) {  // "i" will be our fast pointer
            if (arr[i] != key) {
                arr[nextElement] = arr[i];
                nextElement++;
            }
        }
        return nextElement;
    };
};

int main() {
    Solution s;
    vector<int> arr = {3, 2, 3, 6, 3, 10, 9, 3};
    int length = s.removeKey(arr, 3);
    cout << length << endl;
}