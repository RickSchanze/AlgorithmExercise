/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == nullptr) return nullptr;
        ListNode* First = head;
        ListNode* Second = head;
        ListNode* Dummy = new ListNode(0, head);
        ListNode* BeforeSecond = Dummy;
        ListNode* BeforeFirst = Dummy;
        ListNode* Loop = head;
        int i = 0;
        while (Loop != nullptr) {
            i++;
            Loop = Loop->next;
        }
        if (k >= i)
            k = k % i;
        if (k == 0) {
            return Dummy->next;
        }
        for (int i = 0; i < k; i++) {
            BeforeSecond = BeforeSecond->next;
            Second = Second->next;
        }
        while (Second != nullptr) {
            BeforeFirst = First;
            First = First->next;
            BeforeSecond = BeforeSecond->next;
            Second = Second->next;
        }
        BeforeSecond->next = head;
        Dummy->next = First;
        BeforeFirst->next = nullptr;
        return Dummy->next;
    }
};
// @lc code=end
int main()
{
    auto ans = Solution().rotateRight(new ListNode(1), 1);
}
