#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
  void sort(vector<vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
      if (a[0] < b[0])
        return true;
      return false;
    });
  }
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals);
    vector<vector<int>> ans;
    for (auto v : intervals) {
      if (ans.empty()) {
        ans.push_back(v);
        continue;
      }
      auto &last = ans.back();
      if (last[1] >= v[0]) {
        if (last[1] <= v[1]) {
          last[1] = v[1];
        }
        continue;
      } else {
        ans.push_back(v);
      }
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  vector<vector<int>> in = {{1,4}, {0,4}};
  //   vector<vector<int>> in = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  Solution().merge(in);
}
