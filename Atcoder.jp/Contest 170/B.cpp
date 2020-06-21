#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    string ans = "No";
    // x animals, y legs
    for (int i = 0; i < x + 1; i++) {
        int remaining = x - i;                 // Get remaining animals
        if ((2 * i) + (4 * remaining) == y) {  // If ith animal has 2 legs, check remaining for 4 to see if it adds up to total
            ans = "Yes";
        }
    }
    cout << ans << endl;
    return 0;
}