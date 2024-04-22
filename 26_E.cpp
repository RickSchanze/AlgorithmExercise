#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int cur = -1, next = 0, k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cur == -1) {
                k++;
                cur++;
                next++;
                continue;
            }
            if (nums[i] != nums[cur]) {
                nums[next++] = nums[i];
                cur++;
                k++;
            }
        }
        return k;
    }
};
// @lc code=end

int main()
{
    auto nums = vector<int> { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    Solution().removeDuplicates(nums);
}