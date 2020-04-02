#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int H, N;
    cin >> H >> N;
    bool flag = false;
    while (N > 0) {
        int num;
        cin >> num;
        H -= num;
        N--;
    }

    if (H <= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
