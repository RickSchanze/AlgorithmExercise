/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end());
        unordered_map<int, int> m;
        for (auto num : citations) {
            for (auto& pair : m) {
                if (pair.first <= num) {
                    pair.second++;
                }
            }
            if (m.count(num) == 0)
                m[num]++;
        }
        int h = 0;
        for (auto num : m) {
            int a = min(num.second, num.first);
            h = max(h, a);
        }
        return h;
    }
};
// @lc code=end
int main()
{
    vector<int> a = { 1, 1 };
    Solution().hIndex(a);
}

class B1 {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            h++;
            i--;
        }
        return h;
    }
};
