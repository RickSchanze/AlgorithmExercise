/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if (indices.count(val) > 0) return false;
        int index = nums.size();
        nums.push_back(val);
        indices[val] = index;
        return true;
    }
    
    bool remove(int val) {
        if (indices.count(val) == 0) return false;
        int index = indices[val];
        int last = nums.back();
        nums[index] = last;
        indices[last] = index;
        nums.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }

    private:
    vector<int> nums;
    unordered_map<int, int> indices;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

