class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int low = 0, high = total;
        int ans = INT_MAX;

        // cout << high << endl;
        if(k>n){
            return -1;
        }

        while(low <= high){
            int mid = (low+high)/2;

            int count = 0;
            int std_pgs = 0;
            int i = 0;

            while(i < n){
                if(nums[i] > mid){
                    low = mid+1;
                    break;
                }
                else if(nums[i]+std_pgs <= mid){
                    std_pgs += nums[i];
                    i++;
                    if(i==n)
                        count++;
                }
                else{
                    count++;
                    std_pgs = 0;
                }
            }
            // cout << mid << " " << count << endl;
            if(i==n){
                if(count <= k){
                    // cout << mid << " " << count<< endl;
                    ans = min(ans, mid);
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return ans;
    }
};