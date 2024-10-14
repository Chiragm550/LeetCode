class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        int n = nums.size();
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    int adjIncrEle(vector<int> &nums){
        int i=0, j=1;
        int maxi = -1;
        while(j<nums.size()){
            if(nums[i] < nums[j]){
                maxi = max(maxi, i);
            }
            i++;
            j++;
        }
        return maxi;
    }

    int maxj(vector<int>& nums, int i){
        int maxJ = 0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j] > i){
                maxJ = max(maxJ, j);
            }
        }
        return maxJ;
    }

    void nextPermutation(vector<int>& nums) {
        int i = adjIncrEle(nums);
        if(i != -1){
            int maxJ = maxj(nums, nums[i]);
            swap(nums[maxJ], nums[i]);
            cout << maxJ;
            reverse(nums, i+1, nums.size()-1);
        }
        else{
            reverse(nums, 0, nums.size()-1 );
        }
    }
};