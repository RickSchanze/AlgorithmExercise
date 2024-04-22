/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size()), right(nums.size());
        left[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            left[i] = (left[i - 1] * nums[i]);
        }
        right[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            right[i] = nums[i] * right[i + 1];
        }
        vector<int> rtn;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0){
                rtn.push_back(right[i + 1]);
                continue;
            }
            if (i == nums.size() - 1) {
                rtn.push_back(left[i - 1]);
                continue;
            }
            rtn.push_back(left[i - 1] * right[i + 1]);
        }
        return rtn;
    }
};
// @lc code=end

int main() {
    vector<int> a = {-1,1,0,-3,3};
    Solution().productExceptSelf(a);
}