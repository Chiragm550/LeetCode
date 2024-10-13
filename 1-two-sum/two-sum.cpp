class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> indices;
        int idx = 0;
        map<int, int> mpp;

        while(idx < nums.size()){
            int second = target - nums[idx];
            if(mpp.find(second) != mpp.end()){
                indices.push_back(idx);
                indices.push_back(mpp[second]);
                return indices;
            }
            else{
                mpp[nums[idx]] = idx;
            }
            idx++;
        }
        return {};
    }
};