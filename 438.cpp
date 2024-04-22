#include <bitset>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
  bool equal(int a[26], int b[26]) {
    for (int i = 0; i < 26; i++) {
      if (a[i] != b[i]) {
        return false;
      }
    }
    return true;
  }
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int pb[26] = {0};
    for (auto c : p) {
      pb[c - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
      int ib[26] = {0};
      for (int j = i; j < i + p.size() && j < s.size(); j++) {
        ib[s[j] - 'a']++;
      }
      if (equal(pb, ib)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution().findAnagrams("cbaebabacd", "abc");
  ;
}

// 更好的解法
// 滑动窗口
class BetterSolution {
  vector<int> findAnagrams(string s, string p) {
    int sLen = s.size(), pLen = p.size();
    if (sLen < pLen) {
      return {};
    }

    vector<int> ans;
    vector<int> sCount(26);
    vector<int> pCount(26);

    // 首先构建初始的滑动窗口
    for (int i = 0; i < p.size(); i++) {
      ++sCount[s[i] - 'a'];
      ++pCount[p[i] - 'a'];
    }

    if (sCount == pCount) {
      ans.emplace_back(i);
    }

    for (int i = 0; i < sLen - pLen; i++) {
      // 滑动一次即对元素进行调整
      --sCount[s[i] - 'a'];
      ++sCount[s[i + pLen] - 'a'];

      if (sCount == pCount) {
        ans.emplace_back(i);
      }
    }
    return ans;
  }
}
