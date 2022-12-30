// 146. LRU Cache

#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
    struct Node
    {
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int key, int val)
            : key{key}, val{val},
              next{nullptr}, prev{nullptr} {}
    };

    Node *head = new Node(0, 0);
    Node *tail = new Node(0, 0);

    unordered_map<int, Node *> m_map;
    int m_capacity = 0;

    void insert(Node *curr)
    {
        curr->next = head->next;
        head->next->prev = curr;
        head->next = curr;
        curr->prev = head;
        m_map[curr->key] = curr;
    }

    void remove(Node *curr)
    {
        m_map.erase(curr->key);
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
    }

public:
    LRUCache(int capacity)
        : m_capacity{capacity}
    {
        head->next = tail;
        head->prev = head;
    }

    int get(int key)
    {
        if (m_map.find(key) != m_map.end())
        {
            Node *cur = m_map[key];
            remove(cur);
            insert(cur);
            return cur->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m_map.find(key) != m_map.end())
            remove(m_map[key]);

        if (m_map.size() >= m_capacity)
            remove(tail->prev);

        insert(new Node(key, value));
    }
};