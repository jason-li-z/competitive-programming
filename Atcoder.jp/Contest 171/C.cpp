#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;
    string result = "";
    while (n > 0) {
        n--;
        result += 'a' + (n % 26);
        n /= 26;
    }

    reverse(result.begin(), result.end());

    cout << result << endl;

    return 0;
}