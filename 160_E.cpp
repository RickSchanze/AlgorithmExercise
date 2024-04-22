#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL){} *
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
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *NodeA = headA, *NodeB = headB;
    while (NodeA != nullptr) {
      while (NodeB != nullptr) {
        if (NodeB != NodeA) {
          NodeB = NodeB->next;
        } else {
          return NodeB;
        }
      }
      NodeA = NodeA->next;
      NodeB = headB;
    }
    return nullptr;
  }
};
// @lc code=end

class BetterSolution {
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }
    ListNode *pA = headA, *pB = headB;
    while (pA != pB) {
      pA = pA == nullptr ? headB : pA->next;
      pB = pB == nullptr ? headA : pB->next;
    }
    return pA;
  }
};
