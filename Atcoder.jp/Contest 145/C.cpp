#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> pairs(n);

    double tot_dist = 0;

    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    for (int i = 0; i < n; i++) {
        pair<double, double> curr = pairs[i];
        for (int j = i + 1; j < n; j++) {
            double curr_x = pairs[i].first;
            double curr_y = pairs[i].second;

            double y_x = pairs[j].first;
            double y_y = pairs[j].second;

            tot_dist += (sqrt(pow((curr_x - y_x), 2) + pow((curr_y - y_y), 2))) * 2 / n;
        }
    }

    cout << setprecision(10) << tot_dist << endl;

    return 0;
}