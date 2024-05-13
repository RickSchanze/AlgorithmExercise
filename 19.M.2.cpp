/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
#include <bits/stdc++.h>
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* Dummy = new ListNode(0, head);
        ListNode* First = Dummy;
        ListNode* Second = head;
        for (int i = 0; i < n; i++) {
            Second = Second->next;
        }
        while (Second != nullptr) {
            Second = Second->next;
            First = First->next;
        }
        First->next = First->next->next;
        return Dummy->next;
    }
};
// @lc code=end
int main()
{
    Solution().removeNthFromEnd(new ListNode(1, new ListNode(2)), 2);
}
