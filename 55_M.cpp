/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        int rightMost = 0;
        for (int i = 0; i < n; i++) {
            if (i <= rightMost) {
                rightMost = max(rightMost, i + nums[i]);
                if (rightMost >= n - 1)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
int main()
{
    vector<int> a = { 2, 0 };
    cout << Solution().canJump(a);
}