class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int s_num = 0;
        for(int i = 0; i<n; i++){
            s_num = s_num ^ nums[i];
        }
        return s_num;
    }
};