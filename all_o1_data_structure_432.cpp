// 432. All O`one Data Structure

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Node
{
public:
    int freq;
    Node *prev;
    Node *next;
    unordered_set<string> keys;

    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {}
};

class AllOne
{
    Node *front;
    Node *rear;
    unordered_map<string, Node *> map;

public:
    AllOne()
    {
        front = new Node(0);
        rear = new Node(0);
        front->next = rear;
        rear->prev = front;
    }

    void inc(string key)
    {
        if (map.find(key) == map.end()) {
            Node *firstNode = front->next;
            if (firstNode == rear or firstNode->freq > 1) {
                Node *newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->prev = front;
                newNode->next = firstNode;
                front->next = newNode;
                firstNode->prev = newNode;
            } else {
                firstNode->keys.insert(key);
            }
            map[key] = firstNode;
            return;
        }

        Node *node = map[key];
        int freq = node->freq;
        node->keys.erase(key);

        Node *nextNode = node->next;
        if (nextNode == rear or nextNode->freq != freq + 1) {
            Node *newNode = new Node(freq + 1);
            newNode->keys.insert(key);
            newNode->prev = node;
            newNode->next = nextNode;
            node->next = newNode;
            nextNode->prev = newNode;
            map[key] = newNode;
        } else {
            nextNode->keys.insert(key);
            map[key] = nextNode;
        }

        if (node->keys.empty())
            removeNode(node);
    }

    void dec(string key)
    {
        if (map.find(key) == map.end())
            return;

        Node *node = map[key];
        node->keys.erase(key);
        int freq = node->freq;

        if (freq == 1)
            map.erase(key);
        else {
            Node *prevNode = node->prev;
            if (prevNode == front or prevNode->freq != freq - 1) {
                Node *newNode = new Node(freq - 1);
                newNode->keys.insert(key);
                newNode->prev = prevNode;
                newNode->next = node;
                prevNode->next = newNode;
                node->prev = newNode;
                map[key] = newNode;
            } else {
                prevNode->keys.insert(key);
                map[key] = prevNode;
            }
        }

        if (node->keys.empty())
            removeNode(node);
    }

    string getMaxKey()
    {
        if (rear->prev == front)
            return "";
        return *(rear->prev->keys.begin());
    }

    string getMinKey()
    {
        if (front->next == rear)
            return "";
        return *(front->next->keys.begin());
    }

    void removeNode(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete node;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

// The above does not work

class Node {
public:
    int freq;
    Node* prev;
    Node* next;
    unordered_set<string> keys;

    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    Node* head;                        // Dummy head
    Node* tail;                        // Dummy tail
    unordered_map<string, Node*> map;  // Mapping from key to its node

public:
    // Initialize your data structure here.
    AllOne() {
        head = new Node(0);  // Create dummy head
        tail = new Node(0);  // Create dummy tail
        head->next = tail;   // Link dummy head to dummy tail
        tail->prev = head;   // Link dummy tail to dummy head
    }

    // Inserts a new key <Key> with value 1. Or increments an existing key by 1.
    void inc(string key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            int freq = node->freq;
            node->keys.erase(key);  // Remove key from current node

            Node* nextNode = node->next;
            if (nextNode == tail || nextNode->freq != freq + 1) {
                // Create a new node if next node does not exist or freq is not
                // freq + 1
                Node* newNode = new Node(freq + 1);
                newNode->keys.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
                node->next = newNode;
                nextNode->prev = newNode;
                map[key] = newNode;
            } else {
                // Increment the existing next node
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }

            // Remove the current node if it has no keys left
            if (node->keys.empty()) {
                removeNode(node);
            }
        } else {  // Key does not exist
            Node* firstNode = head->next;
            if (firstNode == tail || firstNode->freq > 1) {
                // Create a new node
                Node* newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->prev = head;
                newNode->next = firstNode;
                head->next = newNode;
                firstNode->prev = newNode;
                map[key] = newNode;
            } else {
                firstNode->keys.insert(key);
                map[key] = firstNode;
            }
        }
    }

    // Decrements an existing key by 1. If Key's value is 1, remove it from the
    // data structure.
    void dec(string key) {
        if (map.find(key) == map.end()) {
            return;  // Key does not exist
        }

        Node* node = map[key];
        node->keys.erase(key);
        int freq = node->freq;

        if (freq == 1) {
            // Remove the key from the map if freq is 1
            map.erase(key);
        } else {
            Node* prevNode = node->prev;
            if (prevNode == head || prevNode->freq != freq - 1) {
                // Create a new node if the previous node does not exist or freq
                // is not freq - 1
                Node* newNode = new Node(freq - 1);
                newNode->keys.insert(key);
                newNode->prev = prevNode;
                newNode->next = node;
                prevNode->next = newNode;
                node->prev = newNode;
                map[key] = newNode;
            } else {
                // Decrement the existing previous node
                prevNode->keys.insert(key);
                map[key] = prevNode;
            }
        }

        // Remove the node if it has no keys left
        if (node->keys.empty()) {
            removeNode(node);
        }
    }

    // Returns one of the keys with maximal value.
    string getMaxKey() {
        if (tail->prev == head) {
            return "";  // No keys exist
        }
        return *(tail->prev->keys.begin());  // Return one of the keys from the
                                             // tail's previous node
    }

    // Returns one of the keys with minimal value.
    string getMinKey() {
        if (head->next == tail) {
            return "";  // No keys exist
        }
        return *(
            head->next->keys
                .begin());  // Return one of the keys from the head's next node
    }

private:
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;  // Link previous node to next node
        nextNode->prev = prevNode;  // Link next node to previous node

        delete node;  // Free the memory of the removed node
    }
};