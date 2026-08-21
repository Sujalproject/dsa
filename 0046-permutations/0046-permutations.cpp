class Solution {
public:
    void per(vector<int>& nums,int idx,int n,vector<int> &temp,vector<vector<int>> &ans,vector<bool> &used){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0;i<n;i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            temp.push_back(nums[i]);
            per(nums,idx+1,n,temp,ans,used);

            temp.pop_back();
            used[i] = false;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        per(nums, 0, nums.size(), temp, ans, used);

        return ans;
    }
};