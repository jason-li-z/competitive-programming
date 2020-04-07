#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        if(arr.size() == 0) {
            return 0;
        }
        
        unordered_set<int> s;
        int count = 0;
        for(int a : arr) {
            s.insert(a);
        }
        
        for(int i = 0; i < arr.size(); i++) {
            if(s.find(arr[i]+1) != s.end()) {
                count++;
            }
        }
        
        return count;
    }
};