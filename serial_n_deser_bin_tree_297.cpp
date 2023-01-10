// 297. Serialize and Deserialize Binary Tree

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
    void ser_helper(TreeNode *root, ostringstream &out)
    {
        if (!root)
        {
            out << "# ";
            return;
        }

        out << root->val << ' ';
        ser_helper(root->left, out);
        ser_helper(root->right, out);
    }
    TreeNode *de_ser_helper(istringstream &in)
    {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;

        TreeNode *root = new TreeNode(stoi(val));
        root->left = de_ser_helper(in);
        root->right = de_ser_helper(in);
        return root;
    }

public:
    string serialize(TreeNode *root)
    {
        ostringstream out;
        ser_helper(root, out);
        return out.str();
    }

    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return de_ser_helper(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));