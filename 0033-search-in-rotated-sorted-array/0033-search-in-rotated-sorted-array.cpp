class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>nums[nums.size()-1]){
                if(nums[mid]<target){
                    left = mid+1;
                }
                else{
                    if(nums[0]<=target){
                        right = mid-1;
                    }
                    else{
                        left = mid+1;
                    }
                }
            
            }
            else{
                if(nums[mid]>target){
                    right = mid-1;
                }
                else{
                    if(nums[nums.size()-1]<target){
                        right = mid-1;
                    }
                    else{
                        left = mid+1;
                    }
                }
            }
        }
        return -1;

    }
};