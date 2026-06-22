// 707. Design Linked List

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

struct Node {
    int val;
    Node *prev;
    Node *next;

    Node(int val = 0, Node *prev = nullptr, Node *next = nullptr)
        : val(val), prev(prev), next(next) {}
};

class MyLinkedList
{
    Node head;
    Node tail;
    int size = 0;

public:
    MyLinkedList()
    {
        head.next = &tail;
        tail.prev = &head;
    }

    int get(int index)
    {
        if (index < 0 || size <= index)
            return -1;

        Node *cur = head.next;
        int cur_idx = 0;
        while (cur_idx < index) {
            cur = cur->next;
            cur_idx++;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        Node *cur = head.next;
        Node *node = new Node(val, &head, cur);
        head.next = node;
        cur->prev = node;
        size++;
    }

    void addAtTail(int val)
    {
        Node *cur = tail.prev;
        Node *newNode = new Node(val, cur, &tail);
        tail.prev = newNode;
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0)
            index = 0;
        if (size < index)
            return;
        Node *cur = head.next;
        int cur_idx = 0;
        while (cur_idx < index) {
            cur = cur->next;
            cur_idx++;
        }
        Node *newNode = new Node(val, cur->prev, cur);
        cur->prev->next = newNode;
        cur->prev = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || size <= index)
            return;
        Node *cur = head.next;
        int cur_idx = 0;
        while (cur_idx < index) {
            cur = cur->next;
            cur_idx++;
        }
        Node *nextNode = cur->next;
        Node *prevNode = cur->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete cur;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
