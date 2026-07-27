struct cmp {
    bool operator()(const pair<int,int>& a,
                    const pair<int,int>& b) const {
         if(a.first!=b.first)
            return a.first<b.first;
        return a.second<b.second;

    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for (int i = 0; i < arr.size(); i++) {
            int dist = abs(arr[i]-x);

            pq.push({dist, arr[i]});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while (!pq.empty()) {
            int idx = pq.top().second;
            ans.push_back(idx);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};