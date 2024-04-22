/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

#include <bits/stdc++.h>
#include <cstddef>
#include <regex>
#include <tuple>
#include <type_traits>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

// @lc code=start
// 不要想复杂了,就是简单的一次找出k个然后把这个k翻转
class Solution {
public:
    ListNode *start, *end;

    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy; // 待翻转前驱
        ListNode* end = dummy; // 待翻转末尾

        while (end->next != nullptr) {
            for (int i = 0; i < k && end != nullptr; i++) end = end->next;
            if (end == nullptr) break;
            ListNode* start = pre->next;
            ListNode* next = end->next;
            end->next = nullptr;
            pre->next = reverse(start);
            start->next = next;
            pre = start;
            
            end = pre;
        }
        return dummy->next;
    }
};
// @lc code=end

int main()
{
    Solution().reverseKGroup(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 2);
}
