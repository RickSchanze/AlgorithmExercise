#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    // 方法: 前缀和
    unordered_map<int, int> mp;
    mp[0] = 1; // 第一次满足等于k时会形成 pre - k == 0, 为了加上这个于是m[0] = 1
    int count = 0, pre = 0;
    for (auto &x : nums) {
      pre += x;
      if (mp.find(pre - k) != mp.end()) {
        count += mp[pre - k];
      }
      mp[pre]++;
    }

    return count;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  vector<int> a = {1, -1, 0};
  int k = 0;
  std::cout << Solution().subarraySum(a, k);
}
