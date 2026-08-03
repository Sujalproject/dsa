struct cmp {
    bool operator()(const pair<int,char>& a,
                    const pair<int,char>& b) const {
         if(a.first!=b.first)
            return a.first<b.first;
        return a.second<b.second;

    }
};
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>, vector<pair<int,char>>, cmp> pq;
         for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto i:mp){
            int freq = i.second;
            int ele = i.first;
            pair<int,char> corr = {freq,ele};
            pq.push(corr);
        }
        int seat = 0;
        string res = "";
        while(!pq.empty()){
            pair<int,char>p = pq.top();
            pq.pop();
            if(seat == 0 || res[seat-1]!=p.second){
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first>0){
                    pq.push(p);
                }

            }
            else{
                if(pq.empty()){
                    return "";
                }
                pair<int,char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                seat++;
                p2.first--;
                if(p2.first>0){
                    pq.push(p2);
                }
                pq.push(p);
            }

        }
        return res;
    }
};