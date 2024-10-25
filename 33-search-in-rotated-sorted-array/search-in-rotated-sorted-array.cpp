class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int pivot = INT_MAX;
        int pivotIdx = -1;
        int prevP = pivot;

        while(low <= high){
            int mid = (low+high)/2;
            pivot = min(pivot, nums[mid]);
            if(pivot != prevP){
                pivotIdx = mid;
            }
            prevP = pivot;
            if(nums[low] <= nums[mid] && nums[high] < nums[low]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        low = 0, high = n-1;

        // cout << pivot << endl;

        if(nums[pivotIdx] == target)
            return pivotIdx;
        else{
            if(pivotIdx+1<n && pivotIdx-1>=0){
                if(target >= nums[low] && target <= nums[pivotIdx-1]){
                    high = pivotIdx-1;
                }
                else if(target >= nums[pivotIdx+1] && target <= nums[high]){
                    low = pivotIdx+1;
                }
            }
        }

        while(low <= high){
            int mid = (low+high)/2;
            // cout << mid << ' ';
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return -1;
    }
};

// 8 0 1 2 3 4 5 6 7