/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> s;
        int t1, t2;
        for (const auto& str : tokens) {
            switch (str[0]) {
            case '+': {
                t1 = s.top();
                s.pop();
                t2 = s.top();
                s.pop();
                s.push(t1 + t2);
                break;
            }
            case '-': {
                if (str.size() == 1) {
                    t1 = s.top();
                    s.pop();
                    t2 = s.top();
                    s.pop();
                    s.push(t2 - t1);
                    break;
                } else {
                    int num = std::stoi(str);
                    s.push(num);
                }
                break;
            }
            case '*': {
                t1 = s.top();
                s.pop();
                t2 = s.top();
                s.pop();
                s.push(t1 * t2);
                break;
            }
            case '/': {
                t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();
                s.push(t2 / t1);
                break;
            }
            default:
                int num = std::stoi(str);
                s.push(num);
                break;
            }
        }
        return s.top();
    }
};
// @lc code=end
int main()
{
    vector<string> strs = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    auto ans = Solution().evalRPN(strs);
}
