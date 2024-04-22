/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            // 如果不等于0那么它肯定不是边上的那个数
            // 可以直接下一
            if (num_set.count(num - 1) == 0) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
// @lc code=end
int main()
{
    vector<int> nums = { 100, 4, 200, 1, 3, 2 };
    auto ans = Solution().longestConsecutive(nums);
}
