class Solution {
public:
    void fun(vector<int>& candidates,int n,int idx, vector<int>& temp,              vector<vector<int>>& res,int sum,int target){
        if(idx==n){
            if(sum==target){
                res.push_back(temp);
            }
            return;
        }
        fun(candidates,n,idx+1,temp,res,sum,target);
        if(sum+candidates[idx] <=target){
            temp.push_back(candidates[idx]);
            sum+=candidates[idx];
            fun(candidates,n,idx,temp,res,sum,target);
            temp.pop_back();
            sum-=candidates[idx];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        vector<int> temp;
        vector<vector<int>> res;
        int idx = 0;
        fun(candidates,n,idx,temp,res,sum,target);
        return res;
    }
};