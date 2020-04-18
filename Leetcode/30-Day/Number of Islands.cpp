#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid);  // DFS to Traverse the grid and mark the ones we've seen
                }
            }
        }
        return count;
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size() || grid[i][j] == '0') {
            return;  // If out of bounds or we've already seen it just return
        }
        grid[i][j] = '0';     // Mark it to 0
        dfs(i + 1, j, grid);  // Traverse in all directions
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
        return;
    }
};