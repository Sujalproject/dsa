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
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
         priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            int j = 0;
            while (j < mat[i].size() && mat[i][j] == 1) {
                count++;
                j++;
            }
            pq.push({count,i});

            if (pq.size() > k)
                pq.pop();
        }
         vector<int> ans;

        while (!pq.empty()) {
            int idx = pq.top().second;
            ans.push_back(idx);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};