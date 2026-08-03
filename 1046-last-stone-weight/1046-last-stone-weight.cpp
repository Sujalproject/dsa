class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while (pq.size() > 1){
            int f1 = pq.top();
            pq.pop();
            int f2 = pq.top();
            pq.pop();
            int diff = f1-f2;
            pq.push(diff);
        }
        if(pq.empty()) 
            return 0;
        return pq.top();
    }
};