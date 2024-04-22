/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        int nt = 0;
        for (auto c: t) {
            if (c == s[nt]) {
                nt++;
                if (nt >= s.size())
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    std::cout << Solution().isSubsequence("axc", "ahbgdc");
}