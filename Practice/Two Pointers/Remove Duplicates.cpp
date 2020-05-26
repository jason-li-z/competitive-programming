#include <bits/stdc++.h>

using namespace std;

class Solution {
    /**
        Input: [2, 3, 3, 3, 6, 9, 9]
        Output: 4
        Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].
    */
   public:
    int removeDuplicates(vector<int> &arr) {
        if (arr.size() == 0) {
            return 0;
        }
        int nextElement = 1;  // index to represent next non duplicate element
        // We can return nextElement as it will represent the # of nonDuplicates
        for (int curr = 1; curr < arr.size(); curr++) {
            if (arr[nextElement - 1] != arr[curr]) {
                arr[nextElement] = arr[curr];
                nextElement++;
            }
        }
        return nextElement;
    };
};

int main() {
    Solution s;
    vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
    int length = s.removeDuplicates(arr);
    cout << length << endl;
}