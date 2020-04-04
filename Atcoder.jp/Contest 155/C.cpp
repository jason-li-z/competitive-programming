#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    map<string, int> mp;
    int N;
    cin >> N;
    while (N > 0) {
        string st = "";
        cin >> st;
        mp[st]++;
        N--;
    }

    int max_counts = 0;
    for (const auto &a : mp) {
        max_counts = max(a.second, max_counts);
    }
    for (const auto &a : mp) {
        if (a.second == max_counts) {
            cout << a.first << endl;
        }
    }

    return 0;
}