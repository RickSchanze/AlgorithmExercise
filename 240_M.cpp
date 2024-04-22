#include "bits/stdc++.h"
#include <algorithm>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    // for (const auto &row : matrix) {
    //   for (int element : row) {
    //     if (element == target) {
    //       return true;
    //     }
    //   }
    // }
    // return false;
    for (const auto &row : matrix) {
      auto it = lower_bound(row.begin(), row.end(), target);
      if (it != row.end() && *it == target) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end

class BetterSolution {
  // 逐行二分查找
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    for (const auto &row : matrix) {
      auto it = lower_bound(row.begin(), row.end(), target);
      if (it != row.end() &&*it == target) {
        return true;
      }
    }
    return false;
  }
}
