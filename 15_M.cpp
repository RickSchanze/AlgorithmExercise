/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举a
        for (int first = 0; first < n; first++) {
            // 需要和上一次枚举的数不同
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            // c 对应数组最右
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要与上一次枚举的数不同
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                // 保证b在c左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 指针重合 退出循环
                if (second == third) break;
                if (nums[second] + nums[third] == target)
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    auto ans = Solution().threeSum(nums);
}
