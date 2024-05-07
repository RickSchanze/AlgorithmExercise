/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        Node* Loop = new Node(0);
        Node* Res = Loop;
        Node* Dummy = new Node(0);
        Dummy->next = head;
        unordered_map<Node*, Node*> n2n;
        while (Dummy->next != nullptr) {
            Loop->next = new Node(Dummy->next->val);
            n2n[Dummy->next] = Loop->next;
            Dummy = Dummy->next;
            Loop = Loop->next;
        }
        Loop = Res->next;
        while (head != nullptr) {
            if (head->random == nullptr) {
                Loop->random = nullptr;
            } else {
                Loop->random = n2n[head->random];
            }
            Loop = Loop->next;
            head = head->next;
        }
        return Res->next;
    }
};
// @lc code=end
int main() {
    Node* N1 = new Node(7);
    Node* N2 = new Node(13);
    Node* N3 = new Node(11);
    Node* N4 = new Node(10);
    Node* N5 = new Node(1);
    N1->next = N2;
    N2->next = N3;
    N3->next = N4;
    N4->next = N5;
    N2->random = N1;
    N3->random = N5;
    N4->random = N1;
    N5->random = N3;
    auto Res = Solution().copyRandomList(N1);
}
