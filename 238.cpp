#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> L(nums.size()), R(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      if (i == 0)
        L[i] = 1;
      else
        L[i] = L[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (i == nums.size() - 1)
        R[i] = 1;
      else
        R[i] = R[i + 1] * nums[i + 1];
    }
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      ans.push_back(L[i] * R[i]);
    }
    return ans;
  }
};
// @lc code=end
int main(int argc, char **argv) {
  vector<int> test = {1,2,3,4};
  Solution().productExceptSelf(test);
}