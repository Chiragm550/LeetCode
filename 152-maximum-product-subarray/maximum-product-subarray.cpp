class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxmul = INT_MIN;
        int posMul = 1;
        int negMul = 1;
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i] > 0){
                posMul *= nums[i];
                negMul *= nums[i];
                maxmul = max(maxmul, posMul);
            }
            else if(nums[i] < 0){
                negMul *= nums[i];
                maxmul = max(maxmul, negMul);
                if(negMul > 0){
                    posMul = negMul;
                }
                else{
                    posMul = 1;
                }
            }
            else{
                maxmul = max(maxmul, 0);
                posMul = 1;
                negMul = 1;
            }
        }

        posMul = 1;
        negMul = 1;

        for(int i=nums.size()-1; i>=0; i--){
            
            if(nums[i] > 0){
                posMul *= nums[i];
                negMul *= nums[i];
                maxmul = max(maxmul, posMul);
            }
            else if(nums[i] < 0){
                negMul *= nums[i];
                maxmul = max(maxmul, negMul);
                if(negMul > 0){
                    posMul = negMul;
                }
                else{
                    posMul = 1;
                }
            }
            else{
                maxmul = max(maxmul, 0);
                posMul = 1;
                negMul = 1;
            }
        }
        return maxmul;
    }
};