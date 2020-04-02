#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> arr;
    while (n > 0) {
        int num;
        cin >> num;
        arr.push_back(num);
        n--;
    }

    int min_dist = 0;  // Set initial distance 0

    // Find the longest segment one has to walks
    for (int i = 0; i < arr.size() - 1; i++) {
        min_dist = max(min_dist, (arr[i + 1] - arr[i]));
    }

    // Compares if walking from start to end is shorter or not
    min_dist = max(min_dist, arr[0] + k - arr[arr.size() - 1]);

    // At most has to walk this much, so we can just subtract from k
    cout << k - min_dist << endl;

    return 0;
}
