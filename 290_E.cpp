/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> Spilt(string s)
    {
        auto pos = s.find(' ');
        auto initialPos = 0;
        vector<string> rtn;
        while (pos != string::npos) {
            rtn.push_back(s.substr(initialPos, pos - initialPos));
            initialPos = pos + 1;
            pos = s.find(' ', initialPos);
        }
        rtn.push_back(s.substr(initialPos, min(pos, s.size())));
        return rtn;
    }

    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> p2s;
        auto words = Spilt(s);
        if (words.size() != pattern.size())
            return false;
        for (size_t i = 0; i < words.size(); i++) {
            if (p2s.count(pattern[i]) != 0) {
                if (words[i] != p2s[pattern[i]]) {
                    return false;
                }
            } else {
                auto Iter = find_if(p2s.begin(), p2s.end(), [myword = words[i]](const auto& Pair) {
                    return Pair.second == myword;
                });
                if (Iter == p2s.end())
                    p2s[pattern[i]] = words[i];
                else {
                    if (Iter->second == words[i]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
int main() {
    auto ans = Solution().wordPattern("abba", "cat dog dog cat");
}
