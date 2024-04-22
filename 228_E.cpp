/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        if (nums.size() == 0)
            return {};
        vector<string> rtn;
        int start = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != end + 1) {
                if (start == end) {
                    rtn.emplace_back(std::to_string(start));
                } else {
                    rtn.emplace_back(std::to_string(start) + "->" + std::to_string(end));
                }
                start = nums[i];
                end = nums[i];
            } else {
                end++;
            }
        }
        if (start == end) {
            rtn.emplace_back(std::to_string(start));
        } else {
            rtn.emplace_back(std::to_string(start) + "->" + std::to_string(end));
        }
        return rtn;
    }
};
// @lc code=end
int main()
{
    vector<int> nums = { 0,1,2,4,5,7 };
    auto res = Solution().summaryRanges(nums);
}
