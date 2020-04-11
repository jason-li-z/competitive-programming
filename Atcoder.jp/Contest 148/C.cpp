#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll A, B;
    ll result = max(A, B);
    cin >> A >> B;
    // Pretty much Least Common Multiple
    for (int i = 1; i <= B; i++) {
        // If we multiply up to any number that is divisble by B, we've found our LCM
        if ((A * i) % B == 0) {
            result = A * i;
            break;
        }
    }
    cout << result << endl;
    return 0;
}