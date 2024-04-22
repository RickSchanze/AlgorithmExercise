/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l  < r) {
            int sum = numbers[l] + numbers[r];
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                return {l + 1, r + 1};
            }
        }
        return {l, r};
    }
};
// @lc code=end

int main() {
    vector<int> nums = {-1, 0};
    auto ans = Solution().twoSum(nums, -1);
    std::cout << ans[0] << " " << ans[1] << std::endl;
}

