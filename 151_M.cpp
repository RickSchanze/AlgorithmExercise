/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseWords(string s)
    {
        // 先去掉前导和后导空格
        vector<string> ss;
        char* word = strtok(const_cast<char*>(s.c_str()), " ");
        while (true) {

            if (word != nullptr) {
                ss.push_back(word);
                word = strtok(nullptr, " ");
            } else {
                break;
            }
        }
        string rtn;
        for (int i = ss.size() - 1; i >= 0; i--) {
            rtn += ss[i];
            if (i != 0) {
                rtn += " ";
            }
        }
        return rtn;
    }
};

class B1 {
public:
    string reverseWords(string s)
    {
        // 反转整个字符串
        reverse(s.begin(), s.end());
        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后idx移到下一个单词开头
                if (idx != 0)
                    s[idx++] = ' ';
                // 遍历至单词末尾
                int end = start;
                while (end < n && s[end] != ' ') {
                    s[idx++] = s[end++];
                }
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    };
};

// @lc code=end
int main()
{

    cout << B1().reverseWords("  hello world  ");
}