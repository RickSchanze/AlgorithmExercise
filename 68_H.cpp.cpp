/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 长度为n的由空格组成的字符串
    string blank(int n) {return string(n, ' ');}
    // 用sep拼接[left,right)范围内的words组成的字符串
    string join(vector<string>& words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; i++) {
            s += sep + words[i];
        }
        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int right = 0, n = words.size();
        while (true) {
            int left = right; // 当前行的第一个单词在words的位置
            int sum_len = 0;//当前行单词长度之和
            // 确定可以放多少单词 单词之间至少有一个空格
            while (right < n && sum_len + words[right].length() + right - left <= maxWidth) {
                sum_len += words[right++].length();
            }

            // 当前行是最后一行 单词左对齐，且单词之间只有一个空格，行末补充空格
            if (right == n) {
                string s = join(words, left, n, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }

            int numWords = right - left;
            int numSpaces = maxWidth - sum_len;
            // 当前行只有一个单词，则左对齐行末补充空格
            if (numWords == 1) {
                ans.emplace_back(words[left] + blank(numSpaces));
                continue;
            }
            // 不只一个单词
            int avgSpace = numSpaces / (numWords - 1);
            int extraSpace = numSpaces % (numWords - 1);
            // 拼接额外加一个空格的单词
            string s1 = join(words, left, left + extraSpace + 1, blank(avgSpace + 1));
            // 拼接其余单词
            string s2 = join(words, left + extraSpace + 1, right, blank(avgSpace));
            ans.emplace_back(s1 + blank(avgSpace) + s2);
        }
    }
};
// @lc code=end

int main() {
    std::vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    Solution().fullJustify(words, 16);
}
