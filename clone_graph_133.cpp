// 133. Clone Graph

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;

        unordered_map<Node *, Node *> u_map;

        Node *res = new Node(node->val);
        u_map[node] = res;

        queue<Node *> q;
        q.push(node);
        while (q.size())
        {
            Node *front = q.front();
            q.pop();

            for (auto ele : front->neighbors)
            {
                if (u_map.find(ele) == u_map.end())
                {
                    u_map[ele] = new Node(ele->val);
                    q.push(ele);
                }
                u_map[front]->neighbors.push_back(u_map[ele]);
            }
        }

        return res;
    }
};