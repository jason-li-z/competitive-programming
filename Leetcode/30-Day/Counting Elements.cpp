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

class Solution2 {
public:
    int countElements2(vector<int>& arr) {
        if(arr.size() == 0) {
            return 0;
        }
        
        sort(arr.begin(), arr.end());
        int count = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            int current = arr[i];
            if(binary_search(arr.begin(), arr.end(), current + 1)) {
                count++;
            }
        }
        
        return count;
    }
};