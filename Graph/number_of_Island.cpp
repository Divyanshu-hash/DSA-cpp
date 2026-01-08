#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({row, col});

    // 8 directions
    int delRow[] = {-1,-1,-1,0,0,1,1,1};
    int delCol[] = {-1,0,1,-1,1,-1,0,1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nRow = r + delRow[i];
            int nCol = c + delCol[i];

            if (nRow >= 0 && nRow < n &&
                nCol >= 0 && nCol < m &&
                vis[nRow][nCol] == 0 &&
                grid[nRow][nCol] == 1) {

                vis[nRow][nCol] = 1;
                q.push({nRow, nCol});
            }
        }
    }
}

int numIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (vis[row][col] == 0 && grid[row][col] == 1) {
                cnt++;
                bfs(row, col, grid, vis);
            }
        }
    }
    return cnt;
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 1}
    };

    cout << "Number of islands: " << numIsland(grid) << endl;

    return 0;
}
