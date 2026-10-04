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
    vector<int> postorderTraversal(TreeNode* root) const 
    {
        vector<int> ans;

        if (root == nullptr)
        {
            return ans;
        }

        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* last_visited = nullptr;
        
        while (current != nullptr || !st.empty())
        {
            if (current != nullptr)
            {
                st.push(current);
                current = current->left;
            }

            else 
            {
                TreeNode* top = st.top();

                if (top->right != nullptr && top->right != last_visited)
                {
                    current = top->right;
                }

                else
                {
                    ans.push_back(top->val);
                    last_visited = top;
                    st.pop();
                }
            }   
        }

        return ans;
    }
};
