struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int>&b){
        if(a.first!=b.first)
            return a.first<b.first;
        return a.second<b.second;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>> ,cmp>pq;
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            int dist = ((points[i][0]-0)*(points[i][0]-0))+((points[i][1]-0)*(points[i][1]-0));
            mp[i] = dist;
        }
        for(auto i:mp){
           int ele = i.first;
            int dist = i.second;
            pair<int,int> corr = {dist,ele};
            if(pq.size()<k){
                pq.push(corr);
                continue;
            }
            if(corr.first>pq.top().first)
                continue;
            pq.pop();
            pq.push(corr);
        }
        vector<vector<int>> ans;
         while(!pq.empty()){
            ans.push_back({points[pq.top().second][0],points[pq.top().second][1]});
            pq.pop();
        }
        return ans;
    }
};