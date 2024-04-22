#include <bits/stdc++.h>
#include <climits>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    using ll = long long;
    static int firstMissingPositive(vector<int>& nums)
    {
        ll ans = INT_MAX;
        ll minPos = INT_MAX;
        unordered_map<ll, ll> d;
        for (auto num : nums) {
            d[num] = 1;
        }
        for (auto num : nums) {
            if (num >= 0 && num != INT_MAX) {
                int newAns = num + 1;
                if (d[newAns] != 1 && newAns < ans) {
                    ans = newAns;
                }
                if (num >= 0 && num < minPos) {
                    minPos = num;
                }
            }
        }
        if (minPos - 1 > 0) {
            ans = 1;
        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    vector<int> test = { 7, 8, 9, 11, 12 };
    Solution().firstMissingPositive(test);
}

// 置换法
// 如果数组中包含 x∈[1,N]，那么恢复后，数组的第 x−1 为 x。
// 只关注[1,N] 所以把数组原地映射到[1,N],大于N的不处理
class BetterSolution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};