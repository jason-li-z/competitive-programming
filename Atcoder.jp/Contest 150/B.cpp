#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string s = "";
    int length = 0;
    int count = 0;
    cin >> length >> s;
    for (int i = 0; i < length - 2; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}