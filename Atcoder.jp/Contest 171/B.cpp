#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> store(n);
    for (int i = 0; i < n; i++) {
        cin >> store[i];
    }

    sort(store.begin(), store.end());
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += store[i];
    }

    cout << ans << endl;

    return 0;
}