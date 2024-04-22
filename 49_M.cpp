/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <cstddef>
#include <functional>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
struct A {
    vector<int> cnts;
    A(const string& str)
    {
        cnts.resize(26);
        for (auto c : str) {
            cnts[c - 'a']++;
        }
    }
    bool operator==(const A& Other) const
    {
        for (int i = 0; i < 26; i++) {
            if (cnts[i] != Other.cnts[i])
                return false;
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // if (strs.size() == 0)
        //     return {};
        // vector<tuple<A, std::vector<string>>> m;
        // for (auto word : strs) {
        //     auto a = A(word);
        //     bool bInserted = false;
        //     for (auto& v : m) {
        //         if (get<0>(v) == a) {
        //             get<1>(v).emplace_back(word);
        //             bInserted = true;

        //             break;
        //         }
        //     }
        //     if (!bInserted) {
        //         m.push_back({ a, std::vector<string> { word } });
        //     }
        // }
        // vector<vector<string>> rtn;
        // transform(m.begin(), m.end(), back_inserter(rtn), [](const auto& Pair) {
        //     return get<1>(Pair);
        // });
        // return rtn;

        // OFFICIAL SOLUTION:

        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int> {}](const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str : strs) {
            array<int, 26> counts {};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a']++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    vector<string> input = { "eat", "tea", "tan", "ate", "nat", "bat" };
    auto ans = Solution().groupAnagrams(input);
}
