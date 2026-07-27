struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int>&b){
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second>b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>> ,cmp>pq;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            int ele = i.first;
            int freq = i.second;
            pair<int,int> corr = {freq,ele};
            if(pq.size()<k){
                pq.push(corr);
                continue;
            }
            if(corr.first<pq.top().first)
                continue;
            pq.pop();
            pq.push(corr);

        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};