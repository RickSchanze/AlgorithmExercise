/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <bits/stdc++.h>
#include <list>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        vector<list<char>> cos(numRows);
        int index = 0;
        while (index < s.size()) {
            for (int i = 0; i < numRows; i++) 
            {
                if (index >= s.size()) break;
                cos[i].push_back(s[index++]);
            }
            for (int i = numRows - 2; i >= 1; i--) {
                if (index >= s.size()) break;
                cos[i].push_back(s[index++]);
            }
        }
        string rtn;
        for (auto& l : cos) {
            for (auto c: l) {
                rtn += c;
            }
        }
        return rtn;
    }
};
// @lc code=end
int main() {
    cout << Solution().convert("PAYPALISHIRING", 3);
}