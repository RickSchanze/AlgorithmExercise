/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (auto c: ransomNote) {
            m1[c]++;
        }
        for (auto c: magazine) {
            m2[c]++;
        }
        for (auto &[c, count] : m1) {
            if (m2.count(c) == 0) return false;
            if (m2[c] < count) return false;
        }
        return true;
    }
};
// @lc code=end

