#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            // 上涨就购买
            if (prices[i] - prices[i - 1] > 0)
                sum += prices[i] - prices[i - 1];
        }
        return sum;
    }
};
// @lc code=end
// 动态规划
// dp[i][0]=max{dp[i−1][0],dp[i−1][1]+prices[i]}
// dp[i][1]=max{dp[i−1][1],dp[i−1][0]−prices[i]}
class Solution1 {
public:
    int maxProfit(vector<int>& prices)
    {
        int n =prices.size();
        int dp0 = 0, dp1=-prices[0];
        for (int i = 1; i < n; i++) {
            int newDp0 = max(dp0, dp1 + prices[i]);
            int newDp1 = max(dp1, dp0 - prices[i]);
            dp0 = newDp0;
            dp1 = newDp1;
        }
        return dp0;
    }
};