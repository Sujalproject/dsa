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
     vector<vector<int>> res;
   
    void fun(TreeNode* root ,vector<int> maybe){
        if(root == NULL) return;
        maybe.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
                res.push_back(maybe);
                return;
        }
        fun(root->left,maybe);
        fun(root->right,maybe);
        return;
    }
    int sumNumbers(TreeNode* root) {
        vector<int> maybe;
        fun(root,maybe);
        int sum  = 0;
        for(int i = 0;i<res.size();i++){
            int num = 0;
            for(int j = 0;j<res[i].size();j++){
                num = num * 10 + res[i][j];
            }
            sum+=num;
        }
        return sum;
    }
};