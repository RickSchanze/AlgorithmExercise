/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
#if 0
        if (intervals.size() == 0)
            return { newInterval };
        vector<vector<int>> res(intervals.size());
        copy(intervals.begin(), intervals.end(), res.begin());
        auto iter = find_if(res.begin(), res.end(), [mynum = newInterval[0]](const auto& num) {
            return num[0] > mynum;
        });
        if (iter == res.begin()) {
            if (newInterval[0] < (*iter)[1])
                res.insert(res.begin(), newInterval);
            else
                res.push_back(newInterval);
        } else if (iter == res.end()) {
            res.push_back(newInterval);
        } else {
            res.insert(iter, newInterval);
        }
        vector<vector<int>> realres = { res[0] };
        for (int i = 1; i < res.size(); i++) {
            if (res[i][0] <= realres.back()[1]) {
                realres.back()[1] = ::std::max(realres.back()[1], res[i][1]);
            } else {
                realres.push_back(res[i]);
            }
        }
        return realres;
#endif
        // OFFICIAL SOLUTION 模拟
        int left = newInterval[0], right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval : intervals) {
            if (interval[0] > right) {
                // 在插入区间右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            } else if (interval[1] < left) {
                // 插入区间左侧且无交集
                ans.push_back(interval);
            } else {
                // 与插入区间有交集 计算并
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    vector<vector<int>> intervals = { { 1, 5 } };
    vector<int> newInetrval = { 0, 3 };
    auto rtn = Solution().insert(intervals, newInetrval);
}