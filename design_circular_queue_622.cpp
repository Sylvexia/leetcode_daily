// 622. Design Circular Queue

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class MyCircularQueueVec
{
    vector<int> vec;
    int size, capacity;
    int front, rear;

public:
    MyCircularQueueVec(int k)
    {
        capacity = k;
        vec.resize(k);
        size = 0;
        front = 0;
        rear = 0;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;

        vec[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return vec[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        int idx = (rear + capacity - 1) % capacity;
        return vec[idx];
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};

struct Node {
    Node *prev;
    Node *next;
    int val;
    Node(Node *prev, Node *next, int val)
    {
        this->prev = prev;
        this->next = next;
        this->val = val;
    }
};

class MyCircularQueue
{
    Node *left;
    Node *right;
    int size, capacity;

public:
    MyCircularQueue(int k)
    {
        left = new Node(nullptr, nullptr, -1);
        right = new Node(left, nullptr, -1);
        left->next = right;
        size = 0;
        capacity = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        Node *newNode = new Node(right->prev, right, value);
        right->prev->next = newNode;
        right->prev = newNode;
        size++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        Node *node = left->next;
        left->next = left->next->next;
        left->next->prev = left;
        delete node;
        size--;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return left->next->val;
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return right->prev->val;
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};