class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int i = 0, j = 1;
        while(i<n){
            if(j == n){
                j = 0;
            }
            if(nums[i] <= nums[j]){
                i++;
                j++;
            }
            else{
                count++;
                i++;
                j++;
            }
        }

        if(count ==0 || count ==1){
            return true;
        }
        return false;
    }
};