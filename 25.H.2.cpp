/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    void Reverse(ListNode* Pre, ListNode* Begin, ListNode* End)
    {
        ListNode* Last = End->next;
        ListNode* Current = Begin;
        ListNode* Next = Begin->next;
        ListNode* Next2 = Begin->next->next;
        while (Next2 != End->next) {
            Next->next = Current;
            Current = Next;
            Next = Next2;
            Next2 = Next2->next;
        }
        Next->next = Current;
        Begin->next = Last;
        Pre->next = End;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k == 1)
            return head;
        ListNode* Pre = new ListNode(0, head);
        ListNode* Dummy = Pre;
        int Cnt = 0;
        ListNode* CntNode = Pre;
        while (CntNode != nullptr) {
            while (Cnt < k) {
                if (CntNode != nullptr) {
                    CntNode = CntNode->next;
                } else {
                    break;
                }
                Cnt++;
            }
            if (Cnt < k || CntNode == nullptr)
                break;
            ListNode* End = CntNode;
            ListNode* OldPre = Pre->next;
            Reverse(Pre, Pre->next, CntNode);
            Pre = OldPre;
            CntNode = Pre;
            Cnt = 0;
        }
        return Dummy->next;
    }
};
// @lc code=end

int main()
{
    auto ans = Solution().reverseKGroup(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 5);
}
