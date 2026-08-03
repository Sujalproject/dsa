class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        int idx =0;
        int n = capital.size();
        vector<pair<int, int>> pair;
        for(int i=0;i<n;i++){
            pair.push_back({capital[i],profits[i]});
        }

        sort(pair.begin(),pair.end());
         
        while(k--){
            while(idx<n){
                if(pair[idx].first>w){
                    break;
                }
                pq.push(pair[idx].second);
                idx++;

            }
            if(pq.empty()){
                return w;
            }
            w+= pq.top();
            pq.pop();
            
        }
        return w;
    }
};