class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int num_sum = 0;
        for(int i=0; i<n; i++){
            sum += i+1;
            num_sum += nums[i];
        }
        return sum - num_sum;
    }
};