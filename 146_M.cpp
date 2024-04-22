/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <utility>

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode()
        : key(0)
        , prev(nullptr)
        , next(nullptr)
    {
    }
    DLinkedNode(int _key, int _value)
        : key(_key)
        , value(_value)
        , prev(nullptr)
        , next(nullptr)
    {
    }
};

// 双链表+哈希表,哈希表索引存双链表节点
class LRUCache {
public:
    std::unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

    LRUCache(int _capacity)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
        capacity = _capacity;
        size = 0;
    }

    int get(int key)
    {
        if (cache.count(key) == 0) {
            return -1;
        }
        // key存在
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.count(key) == 0) {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        } else {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(DLinkedNode* node)
    {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail()
    {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

    void removeNode(DLinkedNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
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
    LRUCache cache { 2 };
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl;
    cache.put(3, 3);
    std::cout << cache.get(2) << std::endl;
    cache.put(4, 4);
    std::cout << cache.get(1) << std::endl;
    std::cout << cache.get(3) << std::endl;
    std::cout << cache.get(4) << std::endl;
    // cache.put(1,1);
    // cache.put(4,1);
    // std::cout << cache.get(2) << std::endl;
}