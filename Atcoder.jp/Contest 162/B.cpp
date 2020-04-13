#include <iostream>
#define ll long long

using namespace std;

int main() {
    ll sum = 0;
    int n;
    cin >> n;
    while (n > 0) {
        if (n % 5 != 0 && n % 3 != 0) {
            sum += n;
        }
        n--;
    }
    cout << sum << endl;
    return 0;
}