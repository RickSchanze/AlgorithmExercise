#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    vector<vector<int>> newMatrix(matrix.size(), vector<int>(matrix.size()));
    for (int i = 0; i < matrix.size(); i++) {
      int col = matrix.size() - i - 1;
      for (int j = 0; j < matrix.size(); j++) {
        newMatrix[j][col] = matrix[i][j];
      }
    }
    matrix = newMatrix;
  }
};
// @lc code=end

// 原地旋转，四次推导出公式
class BetterSolution1 {
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
      for (int j = 0; j < (n + 1) / 2; ++j) {
        tie(matrix[i][j], matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1],
            matrix[j][n - i - 1]) =
            make_tuple(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1],
                       matrix[j][n - i - 1], matrix[i][j]);
      }
    }
  }
};

class BetterSolution2 {
public:
  // 先水平翻转后对角线翻转
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    // 水平翻转
    for (int i = 0; i < n / 2; ++i) {
      for (int j = 0; j < n; ++j) {
        swap(matrix[i][j], matrix[n - i - 1][j]);
      }
    }
    // 主对角线翻转
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
}