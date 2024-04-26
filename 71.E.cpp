/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string simplifyPath(string path)
    {
        auto spilt = [](const string& s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for (char ch: s) {
                if (ch == delim) {
                    ans.push_back(move(cur));
                    cur.clear();
                }
                else {
                    cur += ch;
                }
            }
            ans.push_back(move(cur));
            return ans;
        };
        vector<string> names = spilt(path, '/');
        vector<string> stack;
        for (string & name: names) {
            if (name == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            else if (!name.empty() && name != ".") {
                stack.push_back(move(name));
            }
        }
        string ans;
        if (stack.empty()) ans = "/";
        else {
            for (string& name : stack) {
                ans += "/" + name;
            }
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    string path = "/a/./b/../../c/";
    auto ans = Solution().simplifyPath(path);
}
