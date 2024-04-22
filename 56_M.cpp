/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const auto& A, const auto& B) {
            return A[0] < B[0];
        });
        vector<vector<int>> rtn;
        rtn.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= rtn.back()[1]) {
                if (intervals[i][1] > rtn.back()[1])
                    rtn.back()[1] = intervals[i][1];
            } else {
                rtn.emplace_back(intervals[i]);
            }
        }
        return rtn;
    }
};
// @lc code=end
int main()
{
    vector<vector<int>> nums = {
        { 1, 4 }, { 2, 3 }
    };
    auto rtn = Solution().merge(nums);
}
