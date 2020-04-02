#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x;
    cin >> x;
    int result = x / 500;             // Amounnt of coins to * 1000 rewards
    int remaining = x % 500;          // Number remaining
    int littleCoins = remaining / 5;  // Get the amount we can with 5 rewards
    cout << result * 1000 + (littleCoins * 5);
    return 0;
}