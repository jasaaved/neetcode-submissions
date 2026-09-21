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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) const {
        stack<TreeNode*> nodes;
        vector<int> ans;
        TreeNode* current = root;

        while (current != nullptr || !nodes.empty()) {
            if (current != nullptr) {
                nodes.push(current);
                current = current->left;
            }

            else {
                current = nodes.top();
                nodes.pop();
                ans.push_back(current->val);
                current = current->right; 
            }
        } 
        
        return ans;
    }
};