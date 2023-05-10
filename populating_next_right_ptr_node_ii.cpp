// 117. Populating Next Right Pointers in Each Node II

#include <bits/stdc++.h>

using namespace std;

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
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;

        queue<Node *> q;
        q.push(root);

        while (q.size())
        {
            int level_size = q.size();
            for (int i = 0; i < level_size; i++)
            {
                auto front = q.front();
                q.pop();

                if (i == level_size - 1)
                    front->next = nullptr;
                else
                    front->next = q.front();

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
        }

        return root;
    }
};