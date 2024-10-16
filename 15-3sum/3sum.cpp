class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        while( i < n ){
            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j < k){
                        if(nums[j] == nums[j-1] && nums[k] == nums[k+1]){
                            j++; k--;
                        }
                        else{
                            break;
                        }
                    }
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
            i++;

            while(i < n){
                if(nums[i] == nums[i-1])
                    i++;
                else
                    break;
            }
        }
        return res;
    }
};

// -4, -1, -1, 0, 1, 2