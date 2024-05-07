/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        ListNode* Dummy = new ListNode(0);
        Dummy->next = head;
        ListNode* Slow = Dummy;
        ListNode* Fast = Dummy;
        while (Fast != nullptr) {
            Slow = Slow->next;
            Fast = Fast->next;
            if (Fast != nullptr) {
                Fast = Fast->next;
            } else {
                return false;
            }
            if (Slow == Fast) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
int main()
{
    ListNode* N1 = new ListNode(3);
    auto* N2 = new ListNode(2);
    auto* N3 = new ListNode(0);
    auto* N4 = new ListNode(4);
    N1->next = N2;
    N2->next = N3;
    N3->next = N4;
    N4->next = N2;
    Solution().hasCycle(N1);
}
