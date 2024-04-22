#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int inf = 1e9;
        int minprice = inf, maxprofit=0;
        for (auto num : prices) {
            minprice = min(minprice, num);
            maxprofit = max(maxprofit, num - minprice);
        }
        return maxprofit;
    }
};
// @lc code=end

int main()
{
    vector<int> a = { 7, 1, 5, 3, 6, 4 };
    cout << Solution().maxProfit(a);
}
