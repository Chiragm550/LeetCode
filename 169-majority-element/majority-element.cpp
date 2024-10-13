class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0], count = 0;
        for(int i=0; i<nums.size(); i++){
            if(majority == nums[i]){
                count++;
            }
            else{
                count--;
            }

            if(count == 0){
                majority = nums[i];
                count++;
            }
        }
        return majority;
    }
};