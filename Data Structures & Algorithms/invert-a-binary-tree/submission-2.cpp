/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) const
    {
        if (root == nullptr) 
        {
            return root;
        }

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) 
        {
            TreeNode* top = st.top();
            st.pop();

            swap(top->left, top->right);

            if (top->right != nullptr)
            {
                st.push(top->right);
            }

            if (top->left != nullptr)
            {
                st.push(top->left);
            }
        }

        return root;
    }
};
