/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// @lc code=start

class Solution {
public:
unordered_map<int, int> table;
    bool isHappy(int n)
    {
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        int res = n;
        do {
            int rest = res;
            int b = rest % 10;
            int num = 0;
            while (b != 0 || rest != 0) {
                rest = (rest - b) / 10;
                num += b * b;
                b = rest % 10;
            }
            res = num;
            if (res == 1)
                return true;
            if (table.find(res) != table.end())
                return false;
            table[res] = res;
        } while (res != n);
        return false;
    }
};
// @lc code=end

int main()
{
    auto res = Solution().isHappy(13);
}
