// 116. Populating Next Right Pointers in Each Node

#include <cstddef>
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next)
    {
    }
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if(!root)
            return nullptr;
        
        queue<Node *> q;
        q.push(root);

        while (q.size()) {
            int qsize = q.size();
            Node *prev = nullptr;
            for (int i = 0; i < qsize; i++) {
                auto front = q.front();
                q.pop();

                front->next = prev;

                if (front->right)
                    q.push(front->right);
                if (front->left)
                    q.push(front->left);

                prev = front;
            }
        }
        return root;
    }
};