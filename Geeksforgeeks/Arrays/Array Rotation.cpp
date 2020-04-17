#include <bits/stdc++.h>
#define ll long long

using namespace std;

// Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.
// input = [1, 2, 3, 4, 5, 6, 7], 2, 7
// output = [3, 4, 5, 6, 7, 1, 2]
void rotate(int* arr, int d, int n) {
    // Time & Space: O(n) & O(d)
    int* result = new int[d];

    for (int i = 0; i < d; i++) {
        result[i] = arr[i];
    }

    for (int i = 0; i < n - d; i++) {
        arr[i] = arr[i + d];
    }

    for (int i = n - d; i < n; i++) {
        arr[i] = result[i - (n - d)];
    }
    delete[] result;
}

int main() {
    int* a = new int[5]{1, 2, 3, 4, 5};
    rotate(a, 4, 5);

    for (int i = 0; i < 5; i++) {
        if (i == 5 - 1) {
            cout << a[i];
        } else {
            cout << a[i] << " ";
        }
    }

    return 0;
}