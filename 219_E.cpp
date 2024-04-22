/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<int, int> num2idx;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            if (num2idx.count(nums[i]) != 0) {
                if (abs(num2idx[nums[i]] - i) <= k)
                    return true;
            } 
            num2idx[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
int main() {
    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;
    auto ans = Solution().containsNearbyDuplicate(nums, k);
}
