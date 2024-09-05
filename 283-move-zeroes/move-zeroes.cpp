class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        while(j<n){
            while(i<n && nums[i]!=0){
                i++;
            }
            while(j<n && nums[j]==0){
                j++;
            }
            if(i<j && i<n && j<n){
                swap(nums[i], nums[j]);
                i++; j++;
            }
            else{
                j++;
            }
        }
    }
};