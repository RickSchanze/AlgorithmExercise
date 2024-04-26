/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class MinStack {
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stack.empty()) {
            min_stack.push_back(val);
            stack.push_back(val);
            return;
        }
        stack.push_back(val);
        if (val <= min_stack.front()) {
            min_stack.insert(min_stack.begin(), val);
            return;
        }
        if (val >= min_stack.back()) {
            min_stack.push_back(val);
            return;
        }
        for (int i = 0; i < min_stack.size(); i++) {
            if (val >= min_stack[i] && val < min_stack[i + 1]) {
                min_stack.insert(min_stack.begin() + i + 1, val);
                break;
            }
        }
    }

    void pop()
    {
        int e = top();
        stack.pop_back();
        min_stack.erase(find(min_stack.begin(), min_stack.end(), e));
    }

    int top()
    {
        return stack.back();
    }

    int getMin()
    {
        return min_stack.front();
    }

    vector<int> stack;
    vector<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
int main()
{
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-1);
    std::cout << s.getMin() << std::endl;
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.getMin() << std::endl;
}
