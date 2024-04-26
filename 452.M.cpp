/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    std::optional<vector<int>> GetIntersection(const vector<int>& A, const vector<int>& B) {
        if (A[1] < B[0]) {
            return {};
        } else if (A[1] == B[0]) {
            return vector<int>{A[1], A[1]};
        }
        vector<int> Rtn(2);
        Rtn[0] = max(A[0], B[0]);
        Rtn[1] = min(A[1], B[1]);
        return Rtn;
    }

    int findMinArrowShots(vector<vector<int>>& points)
    {
        vector<vector<int>> ans;
        sort(points.begin(), points.end(), [](const auto& A, const auto& B) {
            return A[0] < B[0];
        });
        for (int i = 0; i < points.size(); i++) {
            if (i == 0) {
                ans.push_back(points[i]);
                continue;
            }
            auto Int = GetIntersection(ans.back(), points[i]);
            if (Int) {
                ans.back() = Int.value();
            } else {
                ans.push_back(points[i]);
            }
        }
        return ans.size();
    }
};
// @lc code=end
int main() {
    vector<vector<int>> points = {
        {10,16}, {2,8}, {1,6}, {7,12}
    };
    auto ans = Solution().findMinArrowShots(points);
}
