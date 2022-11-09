/*
 * @Author: 快出来了哦
 * @Date: 2022-11-09 03:19:50
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-09 03:33:45
 * @FilePath: /Leecode/Leecode764.cpp
 * @Description: 
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, INT_MAX)); // 注意要初始化为无穷大
        for (auto mine : mines) {
            int x = mine[0], y = mine[1];
            grid[x][y] = 0;
        }
        for (int i = 0; i < n; i++) {
            int up = 0, down = 0, left = 0, right = 0;
            for (int j = 0, k = n - 1; j < n; j++, k--) {
                left = grid[i][j] == 0 ? 0 : left + 1;
                right = grid[i][k] == 0 ? 0 : right + 1;
                up = grid[j][i] == 0 ? 0 : up + 1;
                down = grid[k][i] == 0 ? 0 : down + 1;
                
                grid[i][j] = min(grid[i][j], left); 
                grid[i][k] = min(grid[i][k], right);
                grid[j][i] = min(grid[j][i], up);
                grid[k][i] = min(grid[k][i], down);
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, grid[i][j]);
            } 
        }  
        return res;
    }
};
int main()
{
    return 0;
}