/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr) return nullptr;
        ListNode *First, *Second;
        ListNode* Dummy = new ListNode(0, head);
        ListNode* BeforeFirst = Dummy;
        First = Dummy->next;
        Second = Dummy->next;
        ListNode* Loop = Dummy->next->next;
        while (Loop != nullptr) {
            if (Loop->val == Second->val) {
                Second = Loop;
            } else {
                if (First != Second) {
                    BeforeFirst->next = Second->next;
                    First = Second = Loop;
                } else {
                    BeforeFirst = First;
                    First = First->next;
                    Second = Second->next;
                }
            }
            Loop = Loop->next;
        }
        if (First != Second) {
            BeforeFirst->next = Second->next;
        }
        return Dummy->next;
    }
};
// @lc code=end
int main() {
    Solution().deleteDuplicates(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5))))))));
}
