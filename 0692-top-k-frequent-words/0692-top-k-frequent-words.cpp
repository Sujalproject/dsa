struct cmp{
    bool operator()(const pair<int,string> &a,const pair<int,string>&b){
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second<b.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        priority_queue<pair<int,string>,vector<pair<int,string>> ,cmp>pq;
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        for(auto i:mp){
            string ele = i.first;
            int freq = i.second;
            pair<int,string> corr = {freq,ele};
            if(pq.size()<k){
                pq.push(corr);
                continue;
            }
            if(corr.first<pq.top().first)
                continue;
            if (corr.first == pq.top().first &&
                 corr.second > pq.top().second)
                 continue;
            pq.pop();
            pq.push(corr);

        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};