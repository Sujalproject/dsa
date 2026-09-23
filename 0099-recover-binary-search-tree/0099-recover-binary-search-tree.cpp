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
    TreeNode* b1f= NULL;
    TreeNode* b1s = NULL;
    TreeNode* b2f = NULL;
    TreeNode* b2s = NULL;
    TreeNode* prev=NULL;
    int galat = 0;
    void fun(TreeNode* root){
        if(root == NULL) return;

        fun(root->left);
        if(prev == NULL){
            prev = root;
        }
        else{
            if(prev->val>root->val){
                if(galat == 0){
                    b1f = prev;
                    b1s = root;
                    galat++;
                }
                else{
                    b2f = prev;
                    b2s = root;
                    galat++;
                }
            
            }
            prev = root;
        }
        fun(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        fun(root);
        if(galat==1){
            swap(b1f->val,b1s->val);
        }
        else{
            swap(b1f->val,b2s->val);
        }
        return;
    }
};