#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    unordered_map<int, bool> tmp;
    int x, n;
    cin >> x >> n;

    while (n > 0) {
        int number;
        cin >> number;
        tmp[number] = true;

        n--;
    }

    for (int i = 0; i < x + 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int ans = x + i * j;
            if (tmp.find(ans) == tmp.end()) {
                cout << ans << endl;
                exit;
            }
        }
    }

    return 0;
}