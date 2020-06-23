#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string sub = s.substr(0, n / 2);  // [pos, length]
    string check = sub + sub;
    if (check == s) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}