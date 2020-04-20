#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    int running_sum = 0;
    cin >> N >> M;
    while (M > 0) {
        int days;
        cin >> days;
        running_sum += days;
        M--;
    }

    if (N < running_sum) {
        cout << -1 << endl;
    } else {
        cout << N - running_sum << endl;
    }

    return 0;
}