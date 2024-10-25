class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int minE = INT_MAX;

        while(low <= high){
            int mid = (low+high)/2;
            minE = min(minE, nums[mid]);
            if(nums[low] <= nums[mid] && nums[high] < nums[low]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return minE;
    }
};