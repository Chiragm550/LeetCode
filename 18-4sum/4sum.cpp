class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int start = 0;

        while(start < n){
            int i = start + 1;
            while( i < n ){
                int j = i+1, k = n-1;
                while(j < k){
                    // cout << nums[start] << ' ' << nums[i] << ' ' << nums[j] << ' ' << nums[k] << endl;
                    long sum = (long)nums[start] + (long)nums[i]+(long)nums[j]+(long)nums[k];
                    if(sum == target){
                        res.push_back({nums[start], nums[i],nums[j],nums[k]});
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
                    else if(sum < target){
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

            start++;

            while(start < n){
                    if(nums[start] == nums[start-1])
                        start++;
                    else
                        break;
            }
        }

        return res;
    }
};

// -2, -1, 0, 0, 1, 2