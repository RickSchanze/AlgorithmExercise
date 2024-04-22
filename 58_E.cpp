/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */


#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s)
    {
        bool good = false;
        int e = s.size() - 1;
        int i;
        for (i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (good) {
                    return e - i;
                } else {
                    continue;
                }
            }

            if (s[i] != ' ') {
                if (!good) {
                    good = true;
                    e = i;
                }
            }
        }
        return e - i;
    }
};
// @lc code=end

int main()
{
    int a = Solution().lengthOfLastWord("a");
    return 0;
}
