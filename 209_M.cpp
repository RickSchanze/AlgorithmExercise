/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int rtn = INT_MAX;
        int l = 0, r = l;
        int sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            if (r - l >= rtn) {
                sum -= nums[l];
                l++;
            };
            if (sum >= target) {
                rtn = r - l;
                sum -= nums[l];
                sum -= nums[r];
                l++;
            } else {
                r++;
            }
        }
        if (rtn < INT_MAX) return rtn + 1;
        return 0;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {10,2,3};
    std::cout << Solution().minSubArrayLen(6, nums);
}