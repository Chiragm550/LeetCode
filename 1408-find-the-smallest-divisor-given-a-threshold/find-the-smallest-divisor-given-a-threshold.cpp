class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());

        int minAns = INT_MAX;

        while(low <= high){
            int mid = (low+high)/2;
            int total = 0;
            for(int i=0; i<n; i++){
                total += ceil(double(double(nums[i])/double(mid)));
            }

            if(total <= threshold){
                high = mid-1;
                minAns = min(minAns, mid);
            }
            else{
                low = mid+1;
            }
        }
        return minAns;
    }
};