// 138. Copy List with Random Pointer

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> u_map;
        Node *p = head;
        while (p)
        {
            u_map[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        while (p)
        {
            u_map[p]->next = u_map[p->next];
            u_map[p]->random = u_map[p->random];
            p = p->next;
        }
        return u_map[head];
    }
};