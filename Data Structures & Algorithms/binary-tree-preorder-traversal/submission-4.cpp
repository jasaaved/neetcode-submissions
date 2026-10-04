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
 #include <vector>

 using namespace std;
 
class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) const
    {
        vector<int> ans;

        if (root == nullptr) 
        {
            return ans;
        }
        
        stack<TreeNode*> st;
        TreeNode* current;
        
        st.push(root);

        while (!st.empty())
        {
            current = st.top();
            st.pop();

            ans.push_back(current->val);

            if (current->right != nullptr) 
            {
                
                st.push(current->right);
            }

            if (current->left != nullptr) 
            {
                
                st.push(current->left);
            }
        }

        return ans;
    }
};
