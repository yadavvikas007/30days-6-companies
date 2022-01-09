// Serialize and Deserialize a Binary Tree

// My Profiles--------------------------------------------------------------------
// GFG : https://auth.geeksforgeeks.org/user/vy9690703/profile
// Leetcode : https://leetcode.com/xmenvikas07/
// Codeforces : https://codeforces.com/profile/xmenvikas07
// Codechef : https://www.codechef.com/users/vikas_009

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    void solve(Node *root, vector<int> &res)
    {
        if (!root)
        {
            res.push_back(-1);
            return;
        }
        res.push_back(root->data);
        solve(root->left, res);
        solve(root->right, res);
    }

    Node *build_tree(vector<int> &A, int &idx)
    {
        if ((A.size() - 1) < idx || A[idx] == -1)
        {
            idx++;
            return NULL;
        }
        Node *root = new Node(A[idx++]);
        root->left = build_tree(A, idx);
        root->right = build_tree(A, idx);
        return root;
    }

public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }

    Node *deSerialize(vector<int> &A)
    {
        int idx = 0;
        return build_tree(A, idx);
    }
};