#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    // 单调队列
    int n = nums.size();
    deque<int> q;
    for (int i = 0; i < k; i++) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
    }

    vector<int> ans = {nums[q.front()]};
    for (int i = k; i < n; i++) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
      while (q.front() <= i - k) {
        q.pop_front();
      }
      ans.push_back(nums[q.front()]);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  Solution().maxSlidingWindow(a, k);
}
