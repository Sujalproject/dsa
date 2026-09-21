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
   
    void fun(TreeNode* root , int sum , int target,vector<int> maybe){
        if(root == NULL) return;
        sum+=root->val;
        maybe.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == target){
                res.push_back(maybe);
            }

             return;
        }
        fun(root->left,sum,target,maybe);
        fun(root->right,sum,target,maybe);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> maybe;
        fun(root,sum,targetSum,maybe);
        return res;
    }
};