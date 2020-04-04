#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    string result = "APPROVED";
    while (N > 0) {
        int num;
        cin >> num;
        if (num % 2 == 0 && num % 3 != 0 && num % 5 != 0) {
            result = "DENIED";
        }
        N--;
    }
    cout << result << endl;
    return 0;
}
