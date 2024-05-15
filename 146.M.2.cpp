/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <bits/stdc++.h>
#include <list>
#include <stack>
#include <unordered_map>
using namespace std;
// @lc code=start
class LRUCache {
public:
    struct DLinkNode {
        int Val;
        int Key;
        DLinkNode* Pre;
        DLinkNode* Next;
    };

    DLinkNode* Head;
    DLinkNode* Tail;
    int Size;
    int Capacity;
    unordered_map<int, DLinkNode*> Cache;

    LRUCache(int capacity)
    {
        Head = new DLinkNode {};
        Tail = new DLinkNode {};
        Head->Next = Tail;
        Tail->Pre = Head;
        Capacity = capacity;
        Size = 0;
    }

    void AddToHead(DLinkNode* Node)
    {
        Node->Pre = Head;
        Node->Next = Head->Next;
        Head->Next->Pre = Node;
        Head->Next = Node;
    }

    void MoveToHead(DLinkNode* Node)
    {
        RemoveNode(Node);
        AddToHead(Node);
    }

    DLinkNode* RemoveTail()
    {
        DLinkNode* Node = Tail->Pre;
        RemoveNode(Node);
        return Node;
    }

    void RemoveNode(DLinkNode* Node)
    {
        Node->Pre->Next = Node->Next;
        Node->Next->Pre = Node->Pre;
    }

    int get(int key)
    {
        if (Cache.count(key) == 0)
            return -1;
        DLinkNode* Node = Cache[key];
        MoveToHead(Node);
        return Node->Val;
    }

    void put(int key, int value)
    {
        if (Cache.count(key) == 0) {
            DLinkNode* Node = new DLinkNode {};
            Node->Key = key;
            Node->Val = value;
            Cache[key] = Node;
            AddToHead(Node);
            ++Size;
            if (Size > Capacity) {
                DLinkNode* Removed = RemoveTail();
                Cache.erase(Removed->Key);
                delete Removed;
                --Size;
            }
        } else {
            DLinkNode* Node = Cache[key];
            Node->Val = value;
            MoveToHead(Node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
int main()
{
    auto MyLRUCache = new LRUCache { 1 };
    MyLRUCache->put(1, 1);
    MyLRUCache->put(2, 2);
    std::cout << MyLRUCache->get(1) << std::endl;
    MyLRUCache->put(3, 3);
    std::cout << MyLRUCache->get(2) << std::endl;
    MyLRUCache->put(4, 4);
    std::cout << MyLRUCache->get(1) << std::endl;
    std::cout << MyLRUCache->get(3) << std::endl;
    std::cout << MyLRUCache->get(4) << std::endl;
}
