//994. Rotting Oranges
//Medium
//12.1K
//377
//Companies
//You are given an m x n grid where each cell can have one of three values:
//
//0 representing an empty cell,
//1 representing a fresh orange, or
//2 representing a rotten orange.
//Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
//
//Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
//
// 
//
//Example 1:
//
//
//Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
//Output: 4
//Example 2:
//
//Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
//Output: -1
//Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
//Example 3:
//
//Input: grid = [[0,2]]
//Output: 0
//Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
// 
//
//Constraints:
//
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 10
//grid[i][j] is 0, 1, or 2.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS, since we requrie level by level ( time)
        int n = grid.size();
        int m = grid[0].size();
        //queue({r,c},time)
        queue<pair<pair<int,int>,int>> q; // 
        vector<vector<int>> visited (n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
            }
        }
        int final_time = 0;
        int nei_row[] = {-1,0,+1,0};
        int nei_col[] = {0,1,0,-1};
        while(q.empty() == false){
        	auto ele = q.front();
            int row = ele.first.first; // get row
            int col = ele.first.second; // get col
            int tim = ele.second;
            q.pop();
            final_time = max(final_time,tim);
            for(int i = 0;i < 4; i++){
                int nrow = row + nei_row[i];
                int ncol = col + nei_col[i];
                if( nrow >=0 && nrow < n && ncol >=0 && ncol <m && visited[nrow][ncol] !=2 && grid[nrow][ncol] == 1){
                    visited[nrow][ncol] = 2;
                    q.push({{nrow,ncol},tim+1});
                }
            }
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if (visited[i][j] != 2 && grid[i][j] ==1) return -1;
            }
        }
        return final_time;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution solution;
    int result = solution.orangesRotting(grid);	
    if (result == -1) {
        cout << "It's not possible to rot all oranges." << endl;
    } else {
        cout << "Minimum time to rot all oranges: " << result << " minutes." << endl;
    }

    return 0;
}
