#include <bits/stdc++.h>
#include <cstddef>
#include <shared_mutex>
using namespace std;

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        size_t count = nums.size();
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == val) {
                count--;
                nums[i] = 0;
                for (int j = i; j < nums.size() - 1; j++) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return count;
    }
};
// @lc code=end

class Better1 {
    int removeElement(vector<int>& nums, int val)
    {
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
}
