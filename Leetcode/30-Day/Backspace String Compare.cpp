#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void modifyString(string &s) {
        int i = 0;
        int count = 0;
        while (i < s.length()) {
            if (s[i] == '#') {
                s[i] = '0';
                count++;
            } else {
                if (count > 0) {
                    s[i] = '0';
                    count--;
                }
            }
            i++;
        }
    }

    bool backspaceCompare(string S, string T) {
        string a = S;
        string b = T;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        modifyString(a);
        modifyString(b);
        string sRes = "";
        string tRes = "";
        for (auto const &t : a) {
            if (t != '0') {
                sRes += t;
            }
        }
        for (auto const &t : b) {
            if (t != '0') {
                tRes += t;
            }
        }
        return tRes == sRes;
    }
};