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
class Solution {
public:
    bool fun(TreeNode* p, TreeNode* q){
          if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        bool r1 = fun(p->left,q->right);
        bool r2 = fun(p->right,q->left);
        if(r1 == true && r2 == true){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        bool ans = fun(root->left,root->right);
        return ans;
    }
};