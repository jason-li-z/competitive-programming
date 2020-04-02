#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int n, k;
    cin >> n >> k;
    long long curr = 0;

    while (n > 0) {
        int num;
        cin >> num;
        arr.push_back(num);
        n--;
    }
    if (k >= arr.size()) {
        cout << curr << endl;
    } else {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - k; i++) {
            curr += arr[i];
        }
        cout << curr << endl;
    }

    // sort, use k on end, return sum of 0 to N - k
}
