// 641. Design Circular Deque

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

struct Node {
    int val;
    Node *prev;
    Node *next;
    Node(int val, Node *prev = nullptr, Node *next = nullptr)
        : val{val}, prev{prev}, next{next} {};
};

class MyCircularDeque
{
    Node *front;
    Node *rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k)
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        auto new_node = new Node(value);
        if (front == nullptr) {
            rear = new_node;
            front = new_node;
        } else {
            new_node->next = front;
            front->prev = new_node;
            front = new_node;
        }
        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        auto new_node = new Node(value);
        if (front == nullptr) {
            rear = new_node;
            front = new_node;
        } else {
            new_node->prev = rear;
            rear->next = new_node;
            rear = new_node;
        }
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;

        if (size == 1) {
            front = nullptr;
            rear = nullptr;
        } else {
            Node *next = front->next;
            delete front;
            front = next;
        }

        size--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;

        if (size == 1) {
            front = nullptr;
            rear = nullptr;
        } else {
            Node *prev = rear->prev;
            delete rear;
            rear = prev;
        }

        size--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return front->val;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return rear->val;
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};