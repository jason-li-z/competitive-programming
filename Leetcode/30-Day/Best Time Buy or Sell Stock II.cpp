#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int n = prices.size();
        int track = 0;
        int arr[n];
        for (int i = 0; i < n - 1; i++) {
            int current = prices[i];
            int next = prices[i + 1];
            if (next - current > 0) {
                track += next - current;
            }
        }
        return track;
    }
};