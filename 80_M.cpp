#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
// 普通双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int k = 0, numDuplcated = 0;
        int cur = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (cur == -1) {
                k++;
                numDuplcated++;
                cur++;
                continue;
            }
            if (cur == 0) {
                if (nums[i] == nums[0]) {
                    numDuplcated++;
                    if (numDuplcated <= 2) {
                        nums[++cur] = nums[i];
                        k++;
                    }
                } else {
                    nums[++cur] = nums[i];
                    k++;
                    numDuplcated = 1;
                }
            } else {
                if (nums[i] == nums[cur]) {
                    if (numDuplcated < 2) {
                        nums[++cur] = nums[i];
                        k++;
                        numDuplcated++;
                    }
                } else {
                    nums[++cur] = nums[i];
                    k++;
                    numDuplcated = 1;
                }
            }
        }
        return k;
    }
};
// @lc code=end

// 快慢双指针
class S1 {
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 2) return n;
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
    }
}

int
main()
{
    vector<int> nums = { 1, 2 };
    int n = Solution().removeDuplicates(nums);
}
