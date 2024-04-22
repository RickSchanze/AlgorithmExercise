/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        // if (s.size() != t.size()) return false;
        // unordered_map<char, int> sc;
        // unordered_map<char, int> st;
        // for (auto i = 0; i < s.size(); i++) {
        //     sc[s[i]]++;
        //     st[t[i]]++;
        // }
        // return sc == st;

        // BETTER:
        if (s.size() != t.size()) return false;
        int a[256];
        for (auto c: s) {
            a[c]++;
        }
        for (auto c: t) {
            a[c]--;
            if (a[c] < 0) return false;
        }
        return true;
    }
};
// @lc code=end
int main() {
    auto ans = Solution().isAnagram("aab", "abc");
}