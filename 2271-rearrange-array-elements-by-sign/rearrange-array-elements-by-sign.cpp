class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        vector<int>final;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

        for(int i=0; i<n/2; i++){
            final.push_back(pos[i]);
            final.push_back(neg[i]);
        }
        return final;
    }
};