class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]<nums[mid+1]){
                left = mid+1;
            }
            else{
                ans = mid;
                right = mid;
            }
        }
        if(ans==-1){
            return nums.size()-1;
        }
        else{
            return ans;
        }
    }

};