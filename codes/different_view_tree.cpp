#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// boundary traversal => 1. first print all left nodes except leafnode 2. print all leaf nodes 3. print all right in reverse order
class Solution
{
public:
    vector<int> boundary_traversal;
    void print_left(TreeNode *root)
    {
        while (root->left)
        {
            boundary_traversal.push_back(root->val);
            root = root->left;
        }
    }
    void print_leaf(TreeNode *root)
    {
        if (root->left)
            print_leaf(root->left);
        if (!root->left && !root->right)
        {
            boundary_traversal.push_back(root->val);
        }
        if (root->right)
            print_leaf(root->right);
    }
    vector<int> right;
    void print_right(TreeNode *root)
    {
        while (root->right)
        {
            right.push_back(root->val);
            root = root->right;
        }
    }
    vector<int> boundary(TreeNode *root)
    {
        print_left(root);
        print_leaf(root);
        print_right(root);
        reverse(right.begin(), right.end());
        for (int i = 0; i < right.size() - 1; i++)
        {
            boundary_traversal.push_back(right[i]);
        }
        return boundary_traversal;
    }
};

//  vertical view of binary tree
vector<pair<int, pair<int, int>>> node_coord;
void dfs(TreeNode *root, int x, int y)
{
    if (root == NULL)
        return;
    node_coord.push_back({root->val, {x, y}});
    // x++;
    // y++;
    // dfs(root->right, x, y);
    // x-=2;
    // dfs(root->left, x, y);

    // or

    dfs(root->right, x + 1, y + 1);  // x+1 and y+1 is necessary x++ and y++ give wrong answer 
    dfs(root->left, x - 1, y + 1); 
}

// calculate coordinate and then write according to the coordinates 

