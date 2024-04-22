/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<int> lens(strs.size());
        std::transform(strs.begin(), strs.end(), lens.begin(), [](const string& s) {
            return s.size();
        });
        int min = *min_element(lens.begin(), lens.end());
        if (min <= 0) return "";
        int ans = 0;
        for (int i = 0; i < min; i++) {
            bool yes = true;
            char c = strs[0][i];
            for (auto str: strs) {
                if (str[i] != c) 
                    yes = false;
            }
            if (yes) {
                ans++;
            } else {
                break;
            }
        }
        return string(strs[0].begin(), strs[0].begin() + ans);
    }
};
// @lc code=end

int main() {
    vector<string> s = {"dog","racecar","car"};

    auto s1 = Solution().longestCommonPrefix(s);
    return 0;
}
