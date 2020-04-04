#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    // For any new number, check if there's another number smaller
    int n;
    cin >> n;
    int count = 0;
    int curr_min = INT_MAX;

    // Because the ith number has to be smaller than jth number,
    // So any new input should count only if they're smaller

    while (n > 0) {
        int num;
        cin >> num;
        if (num < curr_min) {
            count++;
            curr_min = num;
        }
        n--;
    }
    cout << count << endl;

    return 0;
}