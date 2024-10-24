class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int idx = 0;

        if(target > nums[high])
            return n;
    
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                idx = max(mid, idx);
                low = mid+1;
            }
            else{
                idx = mid;
                high = mid-1;
            }
        }
        return idx;
    }
};

// 1 3 4 6
// 5