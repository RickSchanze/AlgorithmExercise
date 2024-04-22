/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<char, int> ori, cnt;

    bool check()
    {
        for (const auto& p : ori) {
            if (cnt[p.first] < p.second)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        for (auto c : t) {
            ++ori[c];
        }
        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;
        while (r < (int)s.size()) {
            if (ori.count(s[++r]) != 0) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()){
                    --cnt[s[l]];
                }
                ++l;
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};
// @lc code=end

int main()
{
    Solution().minWindow("ADOCBECODEBANC", "ABC");
}
