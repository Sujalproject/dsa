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
    unordered_map<int,int> mp;

    TreeNode* fun(vector<int>& postorder,int low ,int high,int &idx){
        if(low>high) {
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[idx]);
        idx--;
        int id = mp[node->val];
        
        node->right  = fun(postorder,id+1,high,idx);
        node->left = fun(postorder,low,id-1,idx);
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int idx = postorder.size()-1;
        return fun(postorder,0,inorder.size()-1,idx);
    }
};