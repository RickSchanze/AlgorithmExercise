/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int strStr(string s, string p)
    {
        int n = s.size(), m = p.size();
        if (m == 0)
            return 0;
        //设置哨兵
        s.insert(s.begin(), ' ');
        p.insert(p.begin(), ' ');
        vector<int> next(m + 1);
        //预处理next数组
        for (int i = 2, j = 0; i <= m; i++) {
            while (j and p[i] != p[j + 1])
                j = next[j];
            if (p[i] == p[j + 1])
                j++;
            next[i] = j;
        }
        //匹配过程
        for (int i = 1, j = 0; i <= n; i++) {
            while (j and s[i] != p[j + 1])
                j = next[j];
            if (s[i] == p[j + 1])
                j++;
            if (j == m)
                return i - m;
        }
        return -1;
    }
};
// @lc code=end
int main() {
    Solution().strStr("ababcababa", "aba");
}