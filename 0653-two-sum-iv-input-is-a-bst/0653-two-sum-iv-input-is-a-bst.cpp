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
    stack<TreeNode*> asc;
    stack<TreeNode*> dsc;

    TreeNode* getsmall(){
        if(asc.empty()) return NULL;

        TreeNode* small = asc.top();
        asc.pop();

        TreeNode* rc = small->right;
        while(rc){
            asc.push(rc);
            rc = rc->left;
        }
        return small;
    }
     TreeNode* getbig(){
        if(dsc.empty()) return NULL;

        TreeNode* big = dsc.top();
        dsc.pop();

        TreeNode* lc = big->left;
        while(lc){
            dsc.push(lc);
            lc = lc->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;

        TreeNode* t = root;
        while(t){
            asc.push(t);
            t = t->left;
        }
        t = root;
        while(t){
            dsc.push(t);
            t = t->right;
        }

        TreeNode* i = getsmall();
        TreeNode* j = getbig();

        while(i && j && i!=j && i->val <= j->val){
            int sum = i->val + j->val;

            if(sum>k){
                j = getbig();
            }
            else if(sum<k){
                i = getsmall();
            }
            else{
                return true;
            }
        }
        return false;
    }
};