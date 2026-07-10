class Solution {
public:
    bool cit(vector<int>& citations,int n,int guess){
        int c = 0;
        for(int i=0;i<n;i++){
            if(citations[i]>=guess){
                c++;
                continue;
            }
        }
        if(c>=guess){
            return true;
        }
        else{
            return false;
        }
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0;
        int high = n;
        int ans = 0;
        while(low<=high){
            int guess = low+(high-low)/2;
            if(cit(citations,n,guess)){
                ans = guess;
                low = guess+1;
            }
            else{
                high = guess-1;
            }
        }
        return ans;
    }
};