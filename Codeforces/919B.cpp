#include <bits/stdc++.h>
#define ll long long

using namespace std;

int euclidean_gcd(int a, int b) {
    if (b == 0) return a;
    return euclidean_gcd(b, a % b);
}

int calculate(int num) {
    int ans = 0;
    while (num > 0) {
        ans += (num % 10);
        num /= 10;
    }
    return ans;
}

int main() {
    int k;
    cin >> k;

    int n = 19;

    while (k > 1) {
        n++;
        if (calculate(n) == 10) k--;
    }

    cout << n << endl;

    return 0;
}