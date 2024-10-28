class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low+high)/2;
            if(low == high){
                return nums[mid];
            }
            else if((mid-low)%2 == 0){
                if(nums[mid] == nums[mid-1]){
                    high = mid-2;
                }
                else{
                    low = mid;
                }
            }
            else if((high-mid)%2 == 0){
                if(nums[mid] == nums[mid+1]){
                    low = mid+2;
                }
                else{
                    high = mid;
                }
            }
            else{
                if(nums[mid] == nums[mid-1]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};