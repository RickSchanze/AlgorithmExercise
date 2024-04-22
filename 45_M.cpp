/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
// 类迪杰斯特拉
class Solution {
public:
    int jump(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return 0;
        }
        unordered_map<int, int> can_reach;
        vector<int> cannot_reach;
        for (int i = 0; i < nums.size(); i++) {
            cannot_reach.push_back(i);
        }
        for (int i = 0; i <= nums[0]; i++) {
            if (i < nums.size()) {
                can_reach[i] = 1;
            }
        }
        for (int i = 1; i < cannot_reach.size(); i++) {
            if (i >= nums.size())
                break;
            if (can_reach.count(i) != 0) {
                int min_count = can_reach[i];
                for (int j = 1; j <= nums[i]; j++) {
                    if (can_reach.count(i + j)) {
                        can_reach[i + j] = min(can_reach[i + j], min_count + 1);
                    } else {
                        can_reach[i + j] = 1 + min_count;
                    }
                }
            }
        }
        return can_reach[nums.size() - 1];
    }
};
// @lc code=end

// 贪心
class B1 {
public:
    int jump(vector<int>& nums)
    {
        int ans = 0, start = 0, my_end = 1;
        while (my_end < nums.size()) {
            int maxPos = 0;
            for (int i = start; i < my_end; i++) {
                maxPos = max(maxPos, i + nums[i]);
            }
            start = my_end;
            my_end = maxPos + 1;
            ans++;
        }

        // return ans;

        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; i++) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

int main()
{
    vector<int> a = { 2, 3, 1, 2, 4, 2, 3 };
    B1().jump(a);
}