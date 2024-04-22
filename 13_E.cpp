/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    unordered_map<char, int> table = {
        { 'I', 1 }, { 'V', 5 }, { 'X', 10 },
        { 'L', 50 }, { 'C', 100 }, { 'D', 500 },
        { 'M', 1000 }
    };

    int romanToInt(string s)
    {
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                if (i < s.size() - 1) {
                    if (s[i + 1] == 'V') {
                        num += 4;
                        i++;
                        continue;
                    }
                    if (s[i + 1] == 'X') {
                        num += 9;
                        i++;
                        continue;
                    }
                }
            }
            if (s[i] == 'X') {
                if (i < s.size() - 1) {
                    if (s[i + 1] == 'L') {
                        num += 40;
                        i++;
                        continue;
                    }
                    if (s[i + 1] == 'C') {
                        num += 90;
                        i++;
                        continue;
                    }
                }
            }
            if (s[i] == 'C') {
                if (i < s.size() - 1) {
                    if (s[i + 1] == 'D') {
                        num += 400;
                        i++;
                        continue;
                    }
                    if (s[i + 1] == 'M') {
                        num += 900;
                        i++;
                        continue;
                    }
                }
            }
            num += table[s[i]];
        }
        return num;
    }
};
// @lc code=end

int main()
{
    cout << Solution().romanToInt("MCMXCIV");
}
