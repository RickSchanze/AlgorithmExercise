/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int max = -1;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            if (height[l] < height[r]) {
                max = std::max(max, height[l] * (r - l)) ;
                l++;
            } else {
                max = std::max(max, height[r] * (r - l)) ;
                r--;
            }
        }
        return max;
    }
};
// @lc code=end
int main() {
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    std::cout << Solution().maxArea(heights);
}