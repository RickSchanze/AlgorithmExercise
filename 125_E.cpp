/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include <bits/stdc++.h>
#include <cctype>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            char ll = tolower(s[l]), rl = tolower(s[r]);
            if (!(isalnum(ll))) {
                l++;
                continue;
            }
            if (!isalnum(rl)) {
                r--;
                continue;
            }
            if (ll != rl)
                return false;
            l++;
            r--;
        }
        return true;
    }
};
// @lc code=end
int main()
{
    std::cout << Solution().isPalindrome("0P");
}