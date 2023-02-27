// 427. Construct Quad Tree

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
    array<Node *, 2> m_leaf;
    Node *helper(int i, int j, int n, vector<vector<int>> &grid)
    {
        if (n == 1)
            return m_leaf[grid[i][j]];

        n /= 2;

        Node *tl = helper(i, j, n, grid);
        Node *tr = helper(i, j + n, n, grid);
        Node *bl = helper(i + n, j, n, grid);
        Node *br = helper(i + n, j + n, n, grid);

        if (tl == tr && tl == bl && tl == br)
            return tl;

        return new Node(grid[i][j], false, tl, tr, bl, br);
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        m_leaf[0] = new Node(false, true);
        m_leaf[1] = new Node(true, true);
        return helper(0, 0, grid.size(), grid);
    }
};