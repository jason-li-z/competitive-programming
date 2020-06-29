#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isPathCrossing(string path) {
        unordered_map<int, int> board;
        int x = 0;
        int y = 0;
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == 'N') x++;
            if (path[i] == 'S') x--;
            if (path[i] == 'E') y++;
            if (path[i] == 'W') y--;
            board[x] = y;
        }
        return false;
    }
};

int main() {
    Solution s;
    string tests[2] = {"NES", "NESWW"};
    for (string word : tests) {
        cout << s.isPathCrossing(word) << endl;
    }
}