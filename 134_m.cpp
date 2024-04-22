/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        vector<int> new_cost(gas.size());
        for (int i = 0; i < gas.size(); i++) {
            new_cost[i] = gas[i] - cost[i];
        }
        for (int i = 0; i < new_cost.size(); i++) {
            if (new_cost[i] < 0) {
                continue;
            }
            int sum = 0;
            for (int j = 0; j < new_cost.size(); j++) {
                sum += new_cost[(i + j) % new_cost.size()];
                if (sum < 0)
                    break;
                if (sum == 0) {
                    if (j == new_cost.size() - 1)
                        return i;
                    else
                        break;
                } else {
                    if (j == new_cost.size() - 1)
                        return i;
                    else
                        continue;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    vector<int> gf = {2 };
    vector<int> co = { 2 };
    Solution().canCompleteCircuit(gf, co);
}