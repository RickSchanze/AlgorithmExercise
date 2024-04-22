#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int target = nums.size() / 2;
        unordered_map<int, int> m;
        for (auto num : nums) {
            if (m.count(num) == 0) {
                m[num] = 1;
            } else {
                m[num]++;
            }
            if (m[num] > target) {
                return num;
            }
        }
        return 0;
    }
};
// @lc code=end

//如果将数组 nums 中的所有元素按照单调递增或单调递减的顺序排序，那么下标为 ⌊n/2⌋ 的元素（下标从 0 开始）一定是众数。
class B1 {
public:
    int majorityElement(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// @lc code=start
class B2 {
public:
    // 摩尔投票
    int majorityElement(vector<int>& nums)
    {
        int x = 0, votes = 0;
        for (int num: nums) {
            if (votes == 0) {
                x = num;
            }
            votes += num == x ? 1 : -1;
        }
        return x;
    }
};
// @lc code=end