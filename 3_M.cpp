/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <type_traits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0) return 0;
        int l = 0, r = 0;
        int ans = INT_MIN;
        vector<bool> has(256, false);
        for (; r < s.size();) {
            if (has[s[r]]) {
                while (true) {
                    if (s[l] == s[r]) {
                        has[s[l]] = false;
                        l++;
                        break;
                    } else {
                        has[s[l]] = false;
                        l++;
                    }
                }
            } else {
                has[s[r]] = true;
                r++;
                ans = max(ans, r - l);
            }
        }
        return ans;
    }
};
// @lc code=end
int main() {
    Solution().lengthOfLongestSubstring("bbbbb");
}