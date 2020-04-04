#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string sa, sb;
    // for a
    for (int i = 0; i < b; i++) {
        sa += to_string(a);
    }

    // for b
    for (int i = 0; i < a; i++) {
        sb += to_string(b);
    }
    // print the smaller one
    sa < sb ? cout << sa : cout << sb;

    return 0;
}