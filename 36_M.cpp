/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int rows[9][9] = { 0 };
        int colums[9][9] = { 0 };
        int subboxs[3][3][9] = { 0 };
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int index = c - '0' - 1;
                    rows[i][index]++;
                    colums[j][index]++;
                    subboxs[i / 3][j / 3][index]++;
                    if (rows[i][index] > 1 || colums[j][index] > 1 || subboxs[i / 3][j / 3][index] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
