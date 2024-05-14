/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */
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
    ListNode* partition(ListNode* head, int x)
    {
        if (head == nullptr) return nullptr;
        ListNode* Dummy = new ListNode(0, head);
        ListNode* BeforeMid = Dummy;
        ListNode* Last = Dummy;
        ListNode* Loop = Dummy->next;
        ListNode* FirstLarger = nullptr;
        while (Loop != nullptr) {
            if (Loop->val < x) {
                BeforeMid->next = Loop;
                BeforeMid = Loop;
                if (FirstLarger == nullptr) {
                    Last = Last->next;
                }
            } else {
                if (FirstLarger == nullptr)
                    FirstLarger = Loop;
                Last->next = Loop;
                Last = Loop;
            }
            Loop = Loop->next;
        }
        if (FirstLarger == nullptr) {
            return Dummy->next;
        }
        BeforeMid->next = FirstLarger;
        Last->next = nullptr;
        return Dummy->next;
    }
};
// @lc code=end
int main()
{
    auto Ans = Solution().partition(new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2)))))), 0);
}
