/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        if (s.size() % 2 == 1) {
            return false;
        }
        std::unordered_map<char, char> m ={
            {'}', '{'},
            {']', '['},
            {')', '('},
        };
        for (const auto& c: s) {
            if (m.count(c) != 0) {
                if (ss.empty()) return false;
                if (ss.top() != m[c]) return false;
                else ss.pop();
            } else {
                ss.push(c);
            }
        }
        return ss.empty();
    }
};
// @lc code=end
int main() {
    auto ans = Solution().isValid("]");
}

