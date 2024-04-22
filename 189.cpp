#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int step = k % nums.size();
        if (step == 0)
            return;
        vector<int> ans;
        for (int i = nums.size() - step; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size() - step; i++) {
            ans.push_back(nums[i]);
        }
        nums = ans;
        return;
    }
};