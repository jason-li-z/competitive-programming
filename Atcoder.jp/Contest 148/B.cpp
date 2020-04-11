#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string S, T;
    int N;
    cin >> N >> S >> T;
    string result = "";
    int i = 0;
    int j = 0;
    while (i < S.length() && j < T.length()) {
        result = result + S[i] + T[j];
        i++;
        j++;
    }

    cout << result << endl;

    return 0;
}