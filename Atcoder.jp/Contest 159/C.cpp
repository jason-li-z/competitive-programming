#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Find max volume
    int L;
    cin >> L;
    // Of sum(3) values == L
    // By geometry
    // (l1 * l2 * l3) ^ 1/3 <= l1 + l2 + l3 / 3
    // So l1*l2*l3 <= (l1+l2+l3/3)^3
    printf("%.12f\n", (double)L * L * L / 27);
    return 0;
}
