#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    unordered_map<int, int> seen;
    int N;
    cin >> N;
    while (N > 0) {
        int num;
        cin >> num;
        seen[num]++;
        N--;
    }
    string result = "YES";
    for (const auto &a : seen) {
        if (a.second > 1) {
            result = "NO";
        }
    }
    cout << result << endl;
    return 0;
}