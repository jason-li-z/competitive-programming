#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // There exist an index i <= min(n, m) && sj = tj && si < ti
    int n, length;
    string result = "";
    cin >> n >> length;
    vector<string> tmp(n);
    while (n > 0) {
        string curr;
        cin >> curr;
        tmp.push_back(curr);
        n--;
    }
    sort(tmp.begin(), tmp.end());

    for (auto a : tmp) {
        result += a;
    }
    cout << result << endl;
}