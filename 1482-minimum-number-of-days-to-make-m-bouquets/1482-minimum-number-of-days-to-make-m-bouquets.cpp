class Solution {
public:
    bool bloom(vector<int>& bloomDay,int n,int guess,int m,int k){
        int flower = 0;
        int b  =0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=guess){
                    flower++;
                    if(flower==k){
                        b++;
                        flower = 0;
                    }
            }
            else{
                flower = 0;
            }
        }
        if(b>=m){
            return true;
        }
        else{
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long mul = 1LL * m * k;
        if(mul>n){
            return -1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low<=high){
            int guess = low+(high-low)/2;
            if(bloom(bloomDay,n,guess,m,k)){
                ans = guess;
                high = guess-1;
            }
            else{
                low = guess+1;
            }

        }
        return ans;
    }
};